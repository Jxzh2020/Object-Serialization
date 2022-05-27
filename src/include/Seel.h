#ifndef SEEL_H
#define SEEL_H
#include <utility>
#include <type_traits> 
#include <cstring>
#include "Typefigure.h"
#include "Buffer.h"


struct Seel{
    template <typename T>
    Seel(const T& data);

    template <typename T,typename K>
    Seel(const std::pair<T,K>&);

    template <typename T>
    Seel(const std::vector<T>&);

    template <typename T>
    Seel(const std::list<T>&);

    template <typename T>
    Seel(const std::set<T>&);

    template <typename T,typename K>
    Seel(const std::map<T,K>&);

    ~Seel(){ if(data_) delete[] data_;}

    template <typename T>
    bool writeback(T& des){ memcpy((char*)&des,data_,meta_num*atom_size); return true; }

    template <typename T,typename K>
    bool writeback(std::pair<T,K>&);

    template <typename T>
    bool writeback(std::vector<T>&);
    
    template <typename T>
    bool writeback(std::list<T>&);

    template <typename T>
    bool writeback(std::set<T>&);

    template <typename T,typename K>
    bool writeback(std::map<T,K>&);

    size_t deserialize_frombytes(char* );

    private:
        template <typename T>
        size_t serialize_stl(const T& data);
    public:
        size_t writebytes(char* buf) const;
        size_t getbytes() const;

    Type return_type;       // the class type it should return when deserialized
    int32_t meta_num;       // the total number of elements
    size_t atom_size;       // the size of atomic elements
    char* data_;
};

// default Seel ctor, for atomic types
template <typename T>
Seel::Seel(const T& data): return_type(is_valid_type<T>), meta_num(1), atom_size(sizeof(T)),data_(nullptr) {
    data_ = new char[atom_size*meta_num];
    memcpy(data_,&data,atom_size);
}

// Seel ctor for string class
template<>
Seel::Seel(const std::string& data): return_type(STRING), meta_num(data.length()+1), atom_size(sizeof(char)),data_(nullptr) {
    data_ = new char[atom_size*meta_num];
    memcpy(data_,data.c_str(),atom_size*meta_num);
}

// Seel ctor for STL containers
template <typename T,typename K>
Seel::Seel(const std::pair<T,K>& data): return_type(PAIR), meta_num(2), atom_size(0),data_(nullptr) {
    size_t step;
    /*
    Seel first(data.first);
    Seel second(data.second);
    
    atom_size = first.atom_size + second.atom_size;

    */
    if(is_valid_type<T> == OTHER || is_valid_type<K> == OTHER)
        throw "unspported type in std::pair";
    serialize_stl(data.first);
    serialize_stl(data.second);
}

template <typename T>
Seel::Seel(const std::vector<T>& data): return_type(VECTOR), meta_num(data.size()), atom_size(sizeof(T)), data_(nullptr){
    ;
}

template <typename T>
Seel::Seel(const std::list<T>& data){
    ;
}

template <typename T>
Seel::Seel(const std::set<T>& data){
    ;
}

template <typename T,typename K>
Seel::Seel(const std::map<T,K>& data){
    ;
}


template <typename T>
size_t Seel::serialize_stl(const T& data){
    Seel sub(data);
    char* temp = nullptr;
    char tmp;
    size_t space = sub.getbytes();
    if(atom_size){
        temp = new char[atom_size];
        memcpy(temp,data_,atom_size);
    }
    delete[] data_;
    data_ = new char[atom_size+space];
    memcpy(data_,temp,atom_size);
    sub.writebytes(data_+atom_size);
    atom_size+=space;
    return space;
}

size_t Seel::writebytes(char* buf) const{
    int step = 0;
    char tmp = (int)return_type;
    // type byte
    memcpy(buf+step,&tmp,sizeof(char));
    step+=sizeof(char);
    //
    memcpy(buf+step,(char*)&meta_num,sizeof(int32_t)+sizeof(size_t));
    step+=sizeof(int32_t)+sizeof(size_t);
    //
    if(return_type<= STRING){
        memcpy(buf+step,data_,meta_num*atom_size);
        step+=meta_num*atom_size;
    }
        
    else{
        memcpy(buf+step,data_,atom_size);
        step+=atom_size;
    }
        
    return step;
}
size_t Seel::getbytes() const{
    if(return_type<=STRING)
        return sizeof(char)+sizeof(int32_t)+sizeof(size_t)+meta_num*atom_size;
    else
        return sizeof(char)+sizeof(int32_t)+sizeof(size_t)+atom_size;
}


// write back string
template <>
bool Seel::writeback(std::string& des){
    des = data_;
    return true; 
}

template <typename T,typename K>
bool Seel::writeback(std::pair<T,K>& des){
    T first_;
    K second_;
    size_t step = 0;
    Seel first(first_);
    Seel second(second_);
    step+=(first.deserialize_frombytes(data_));
    second.deserialize_frombytes(data_+step);
    
    first.writeback(first_);
    second.writeback(second_);

    des.first = first_;
    des.second = second_;
    return true;
}

template <typename T>
bool Seel::writeback(std::vector<T>&){
    ;
}

template <typename T>
bool Seel::writeback(std::list<T>&){
    ;
}

template <typename T>
bool Seel::writeback(std::set<T>&){
    ;
}

template <typename T,typename K>
bool Seel::writeback(std::map<T,K>&){
    ;
}

size_t Seel::deserialize_frombytes(char* buf){
    char tmp;
    size_t step = 0;
    int32_t meta_num;
    size_t atom_size;
    size_t total;
    memcpy(&tmp,buf+step,sizeof(char));
    step+=sizeof(char);
    // TODO type check
    
    memcpy((char* )&meta_num,buf+step,sizeof(int32_t));
    step+=sizeof(int32_t);

    memcpy((char* )&atom_size,buf+step,sizeof(size_t));
    step+=sizeof(size_t);
    


    if(return_type == STRING)
        total = meta_num*atom_size;
    else
        total = atom_size;
    this->meta_num = meta_num;
    this->atom_size = atom_size;
    data_  = new char[total];
    memcpy(data_,buf+step,total);
    step+=total;
    std::cout << "the total bytes are " << step << std::endl;
    return step;

}

#endif