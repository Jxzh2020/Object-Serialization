#include "include/Binary.h"
#include <string>
#include <iostream>
#include <typeinfo>

template<typename T>
void test();

int main(){
    test<bool>();
    test<char>();
    test<int>();
    test<float>();
    test<std::string>();
    return 0;
}

template<typename T>
void test(){
    T k,j;
    std::cout << "input source data of " << typeid(k).name() << ": " << std::endl;
    
    std::cin >> k;
    binary::serialize(k,"se.bin");
    binary::deserialize(j,"se.bin");

    std::cout << typeid(k).name() << ": "<< (bool)(k == j) << std::endl;
}