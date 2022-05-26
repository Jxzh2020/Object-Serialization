#ifndef SEEL_H
#define SEEL_H
#include <utility>
#include <type_traits> 
#include <cstring>
#include "Typefigure.h"

template<typename T> //,typename... type>
struct Seel{
    Seel(): return_type(is_valid_type<std::decay<T>::type>), meta_num(0), atom_size(0),data_(nullptr) {}
    Seel(const T& data);
    ~Seel(){
        if(data_)
            delete[] data_;
    }
    const Type return_type;   // the class type it should return when deserialized
    int32_t meta_num;      // the total number of elements
    size_t atom_size;      // the size of atomic elements
    char* data_;
};

template<typename T>
Seel<T>::Seel(const T& data): return_type(is_valid_type<T>), 
                         meta_num(return_type > STRING? data.size():(return_type == STRING? data.length()+1:1)), 
                         atom_size(return_type > STRING? 0:(return_type<CHAR?sizeof(T):sizeof(char))),
                         data_(nullptr)
{
    if(return_type == OTHER)
        throw "Unspported type";
    if(return_type<STRING){
        data_ = new char[sizeof(T)];
        memcpy(data_,&data,meta_num*atom_size);
    }
    else if(return_type == STRING){
        data_ = new char[data.length()+1];
        memcpy(data_,data.c_str(),data.length()+1);
    }
    else{
        ;
    }
}
#endif