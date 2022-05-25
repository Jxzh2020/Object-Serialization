#include <utility>
#include "Typefigure.h"

template<typename T,typename... type>
struct Seel{
    Seel() = delete;
    
    static const Type return_type;   // the class type it should return when deserialized
    static const int32_t meta_num;      // the total number of elements
    static const size_t atom_size;      // the size of atomic elements
};
