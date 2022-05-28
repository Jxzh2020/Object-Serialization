#include <string>
#include <iostream>
#include <typeinfo>
#include "include/Binary.h"
#include "include/Reflection.h"

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
int main(){
    /*
    testbin<bool>();
    testbin<char>();
    testbin<int>();
    testbin<float>();
    */
    testbin<std::string>();
    getchar();
    std::cout << "DEBUG" << std::endl;
    getchar();
    test_pair();
    test_vector();
    test_list();
    test_set();
    test_map();
    User me;
    std::cout << me.age << std::endl;
    std::cout << me.GetInfo().members << std::endl;
    for(auto &i:me.GetInfo().member_names){
        std::cout << i << "_end" << std::endl;
    }
    for(auto &i:me.GetInfo().member_types){
        std::cout << i << "_end" << std::endl;
    }
    for(auto &i:me.gpa){
        std::cout << i << "_end" << std::endl;
    }

    return 0;
}

template<typename T>
void testbin(){
    T k,j;
    std::cout << "input source data of " << typeid(k).name() << ": " << std::endl;
    
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