#include <string>
#include <iostream>
#include <typeinfo>
#include "include/Binary.h"
#include "include/Reflection.h"
#include "include/Seel.h"

#define TEST    binary::serialize(k,"se.bin");                                          \
                binary::deserialize(j,"se.bin");                                        \
                std::cout << typeid(k).name() << ": "<< (bool)(k == j) << std::endl;    \

template<typename T>
void testbin();

void test_pair();
void test_vector();
void test_list();
void test_set();
void test_map();
struct Demo;

void test_usrdefined();

int main(){
    /*
    testbin<bool>();
    testbin<char>();
    testbin<int>();
    testbin<float>();
    */
    
    //std::cout << is_user_defined<bool>::ret << is_user_defined<int>::ret<<"_end" << std::endl;
    //testbin<std::string>();
    //getchar();
    std::cout << "DEBUG" << std::endl;
    /*
    getchar();
    test_pair();
    test_vector();
    test_list();
    test_set();
    test_map();
    */
    test_usrdefined();
    
    User me;
    std::cout << me.age << std::endl;
    std::cout << me._GETINFO().members << std::endl;
    for(auto &i:me._GETINFO().member_names){
        std::cout << i << "_end" << std::endl;
    }
    for(auto &i:me._GETINFO().member_types){
        std::cout << i << "_end" << std::endl;
    }
    for(auto &i:me.gpa){
        std::cout << i << "_end" << std::endl;
    }

    std::cout << "Fine, testing usrdefined type! " << std::endl;
    try{
        //Seel temp(me);
        User you;
        you.id = 3000;
        you.gpa.push_back("yseokk!");
        you.sub[1] = 1.5;
        binary::serialize(me,"se.bin");
        binary::deserialize(you,"se.bin");
        std::cout <<"Juddge me and you: " << (me == you) << std::endl;
    }catch(const char* tmp){
        std::string temp = tmp;
        std::cout <<is_user_defined<User>::ret <<"*********ERROR*********** ::" << temp << std::endl;
    }
    

    return 0;
}

template<typename T>
void testbin(){
    T k,j;
    std::cout << "input source data of " << typeid(k).name() << ": " << std::endl;

    if(is_user_defined<T>::ret)
        std::cout << "****** has one function!!!!**********" << std::endl;
    else
        std::cout << "****** has no function!!!!**********" << std::endl;
    std::cin >> k;
    TEST
}


void test_pair(){
    std::pair<int, bool> k(5,0),j;
    TEST
}

void test_vector(){
    std::vector<std::string> k{"good", "bad"},j;
    TEST
}

void test_list(){
    std::list<std::vector<std::string>> k{{"good","first"}, {"bad","second"}},j;
    TEST
}

void test_set(){
    std::set<std::string> k{"bad","second"},j;
    TEST
}

void test_map(){
    std::map<int,std::string> k,j;
    k[1] = "good";
    TEST
}



struct Demo{
    Demo(){}//id =0; ratio = 0; name = "K"; token.push_back("k");}
    void Init_r(){
        id = 1;
        ratio = 3.1415926535;
        name = "Pass test!";
        token.clear();
        token.push_back("item[1]");
        token.push_back("item[2]");
        token.push_back("item[3]");
    }
    bool operator==(const Demo& rvl){
        if(id==rvl.id)
            if(ratio == rvl.ratio)
                if(name == rvl.name)
                    if(token == rvl.token)
                        return true;
        return false;
    }
    REFLECT(Demo,
            (int), id,
            (float), ratio,
            (std::string), name,
            (std::vector<std::string>), token)
};

void test_usrdefined(){
    Demo src,des;
    src.Init_r();
    //des.Init_r();
    try{
    std::cout << "_FUN1() == " << src._FUN1() << std::endl;
    std::cout << "_FUN2() == " << src._FUN2() << std::endl;
    std::cout << "_FUN3() == " << src._FUN3() << std::endl;
    
    //for(int i = 1;i<=3;i++)
    std::cout << " Getmember<1>::value(src) = " << Getmember<1>::value(src) << std::endl;

    //std::cout << "_FUN4() == " << src._FUN5() << std::endl;

    }catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
    }
    binary::serialize(src,"se.bin");
    std::cout << "Serialization completed!" << std::endl;
    binary::deserialize(des,"se.bin");
    std::cout << TOSTRING(Demo) << (src == des) << std::endl; 
}
