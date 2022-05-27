#include "include/Binary.h"
#include <string>
#include <iostream>
#include <typeinfo>

template<typename T>
void testbin();

void test_pair();
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
    std::cout << typeid(k).name() << ": "<< (bool)(k == j) << std::endl;

}