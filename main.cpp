#include "Binary.h"
#include <string>
#include <iostream>
int main(){
    int t = 1;
    std::string k;
    std::cin >> k;
    std::string j;
    serialize(k,"se.bin");
    deserialize(j,"se.bin");

    std::cout << (k == j) << std::endl;
    return 0;
}