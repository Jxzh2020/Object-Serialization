#ifndef USER_DEFINED_H
#define USER_DEFINED_H
#include <string>
#include <vector>
#include <map>
//#include "Seel.h"
#include "Typefigure.h"
#include "MACRO_EX.h"
#define TOSTRING(type) #type



#define ADD_META                            std::string name;                                                       \
                                            short members;                                                          \
                                            std::vector<std::string> member_names;                                  \
                                            std::vector<Type> member_types

#define ArgCount(...) _ArgCount(__VA_ARGS__, 16,16, 15,15, 14,14, 13,13, 12,12, 11,11, 10,10, 9,9, 8,8, 7,7, 6,6, 5,5, 4, 4, 3,3, 2,2, 1, 1)
#define _ArgCount(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26,_27,_28,_29,_30,_31, COUNT, ...) COUNT




#define _WRAP(T, ...) PUSH_FIELDS_##T(__VA_ARGS__)


#define REFLECT(_structname, ...)           EXPAND_DEFINE(ArgCount(__VA_ARGS__), __VA_ARGS__)                       \
                                            TypeInfo _GETINFO()const{                                               \
                                            TypeInfo temp;                                                          \
                                            unsigned int offset = 0;                                                \
                                            temp.members = ArgCount(__VA_ARGS__);                                   \
                                            temp.name = TOSTRING(_structname);                                      \
                                            PUSH_FIELDS(ArgCount(__VA_ARGS__),__VA_ARGS__)                          \
                                            return temp;}

struct TypeInfo{
    std::string name;
    short members;
    std::vector<std::string> member_names;
    std::vector<Type> member_types;
    std::vector<unsigned int> offset;
};

struct User_sub{
    User_sub(){check = 1;}
    ~User_sub(){}
    bool operator==(const User_sub& rhs){
        return (check == rhs.check);
    }
    REFLECT(User_sub,
            (float) , check);


        
            
 

};


struct User{
    User(){
        id = 3200;
        age = 20;
        gpa = {"good", "second"};
    }
    ~User(){}
    bool operator==(const User& rhs){
        if(id == rhs.id)
            if(age == rhs.age)
                if(gpa == rhs.gpa)
                    return true;
        return false;
    }
    REFLECT(User,
        (int), id,
        (int), age,
        (std::vector<std::string>), gpa,
        (std::map<int,float>), sub);

};


template <typename U>
struct is_user_defined{
    
    template <typename T, TypeInfo(T::*)() const = &T::_GETINFO>
    static constexpr bool check(T*) { return true; };   //  (1)
    static constexpr bool check(...) { return false; }; //  (2)
 
    static constexpr bool ret = check(static_cast<U*>(0));  //  (3)
};



#endif
