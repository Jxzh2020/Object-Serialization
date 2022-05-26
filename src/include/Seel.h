#ifndef SEEL_H
#define SEEL_H
#include <utility>
#include <type_traits> 
#include <cstring>
#include "Typefigure.h"


struct Seel{
    template<typename T>
    Seel(const T& data);
    ~Seel(){ if(data_) delete[] data_;}
    template <typename T>
    bool wb(T& des){ memcpy((char*)&des,data_,meta_num*atom_size); return true; }
    Type return_type;   // the class type it should return when deserialized
    int32_t meta_num;      // the total number of elements
    size_t atom_size;      // the size of atomic elements
    char* data_;
};
template<typename T>
Seel::Seel(const T& data): return_type(is_valid_type<T>), meta_num(1), atom_size(sizeof(T)),data_(nullptr) {
    data_ = new char[atom_size*meta_num];
    memcpy(data_,&data,atom_size);
}

template<>
Seel::Seel(const std::string& data): return_type(STRING), meta_num(data.length()+1), atom_size(sizeof(char)),data_(nullptr) {
    data_ = new char[atom_size*meta_num];
    memcpy(data_,data.c_str(),atom_size*meta_num);
}

template <>
bool Seel::wb(std::string& des){
    des = data_;
    return true; 
}

#endif