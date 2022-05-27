#ifndef USER_DEFINED_H
#define USER_DEFINED_H
#include <vector>

class Iterator{
    public:
        template <typename T>
        Iterator(T*);
        ~Iterator(){}
        template <typename T>
        T& get(int);
        //begin
    private:
        char* start;
        unsigned int cur;
        unsigned int end;
        std::vector<unsigned int> table;
};

template <typename T>
Iterator::Iterator(T* src): start(src), cur(0), end(sizeof(T)), table(){
    while(cur < end){
        
    };
}

#endif