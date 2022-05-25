#include <utility>
#include "Typefigure.h"

template<typename T,typename... type>
struct Seel{
    Seel() = delete;
    Seel(const T& data): return_type(is_valid_type<T>), 
                         meta_num(return_type > STRING? data.size():(return_type == STRING? data.length()+1:1)), 
                         atom_size(return_type > STRING? 0:(return_type<CHAR?sizeof(T):sizeof(char))),
                         data_(data) {}
    const Type return_type;   // the class type it should return when deserialized
    const int32_t meta_num;      // the total number of elements
    const size_t atom_size;      // the size of atomic elements
    const T data_;
};
