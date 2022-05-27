#include "include/Binary.h"
#include <string>
#include <iostream>
#include <typeinfo>

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
    /*  different type deserialized from file
    bool k;
    char j;
    std::cin >> k;
    binary::serialize(k,"se.bin");
    binary::deserialize(j,"se.bin");
    std::cout << typeid(k).name() << ": "<< (bool)(k == j) << std::endl;
    */
    return 0;
}

template<typename T>
void testbin(){
    T k,j;
    std::cout << "input source data of " << typeid(k).name() << ": " << std::endl;
    
    std::cin >> k;
    binary::serialize(k,"se.bin");
    binary::deserialize(j,"se.bin");

    std::cout << typeid(k).name() << ": "<< (bool)(k == j) << std::endl;
}


void test_pair(){
    std::pair<int, bool> k(5,0),j;
    binary::serialize(k,"se.bin");
    binary::deserialize(j,"se.bin");
    std::cout << "std::pair" << ": "<< (bool)(k == j) << std::endl;

}

void test_vector(){
    std::vector<std::string> k{"good", "bad"},j;
    binary::serialize(k,"se.bin");
    binary::deserialize(j,"se.bin");
    std::cout <<"std::vector" << ": "<< (bool)(k == j) << std::endl;

}

void test_list(){
    std::list<std::vector<std::string>> k{{"good","first"}, {"bad","second"}},j;
    binary::serialize(k,"se.bin");
    binary::deserialize(j,"se.bin");
    std::cout << "std::list" << ": "<< (bool)(k == j) << std::endl;

}

void test_set(){
    std::set<std::string> k{"bad","second"},j;
    binary::serialize(k,"se.bin");
    binary::deserialize(j,"se.bin");
    std::cout << "std::set" << ": "<< (bool)(k == j) << std::endl;

}

void test_map(){
    std::map<int,std::string> k,j;
    k[1] = "good";
    binary::serialize(k,"se.bin");
    binary::deserialize(j,"se.bin");
    std::cout << "std::map" << ": "<< (bool)(k == j) << std::endl;

}