#ifndef USER_DEFINED_H
#define USER_DEFINED_H
#include <string>
#include <vector>
#include "Typefigure.h"
#include "MACRO_EX.h"
#define TOSTRING(type) #type



#define ADD_META                            std::string name;                                                       \
                                            short members;                                                          \
                                            std::vector<std::string> member_names;                                  \
                                            std::vector<Type> member_types

#define HMMacroArgCount(...) _HMMacroArgCount(__VA_ARGS__, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define _HMMacroArgCount(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, COUNT, ...) COUNT



#define EXPANSION_ALL(...)      EXPAND_DEFINE(__VA_ARGS__)                                              \
                                                             


#define REFLECT(_structname, ...)           ADD_META;                                                               \
                                            EXPANSION_ALL(__VA_ARGS__)                                              \
                                            _structname(){name = TOSTRING(_structname);                             \
                                            members = HMMacroArgCount(__VA_ARGS__)/2;                               \
                                            PUSH_FIELDS(__VA_ARGS__);                                               \
                                            Init();}
struct user{
    void Init();
    REFLECT(user,int, id,int, age,float, gpa);
    
};
#endif
/*
struct user{
    void Init();
    std::string name; 
    short members; 
    std::vector<std::string> member_names; 
    std::vector<Type> member_types;
    
    user(){
        name = TOSTRING(user); 
        members = HMMacroArgCount(int, id, int, age, float, gpa)/2; 
        member_types.push_back(is_valid_type<int>); 
        member_types.push_back(is_valid_type<int>); 
        member_types.push_back(is_valid_type<float>); 
        member_types.push_back(is_valid_type<_KEEP>); 
        member_types.push_back(is_valid_type<_KEEP>); 
        member_types.push_back(is_valid_type<_KEEP>); 
        PUSH_FIELDS_7(_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP, _KEEP,_KEEP ,_KEEP ,_KEEP , _KEEP, _KEEP, _KEEP, _KEEP, _KEEP,_KEEP, _KEEP,_KEEP,_KEEP,_KEEP,_KEEP)
        Init();
    }



    user(){
        name = TOSTRING(user); 
        members = 3; 
        Init();
    }
};
*/



