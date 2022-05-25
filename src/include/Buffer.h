#ifndef BUFFER_H
#define BUFFER_H
#include <fstream>
#include <iostream>
#include <string>
#include <exception>
#include "Typefigure.h"

class Buffer{
    public:
        explicit Buffer(const std::string& file,const bool state){
            if(state == in)
                fs.open(file,std::ios::in);
            else
                fs.open(file,std::ios::out);
            if(!fs){
                std::ios_base::failure exp("file open failed!");
                throw exp;
            }
                
        }
        template<typename T>
        int32_t writebin(Type , const T&);
        static const bool in = true;
        static const bool out = false;
    private:
        std::fstream fs;
};

template<typename T>
int32_t writebin(Type k, const T& data){
    return 0;
}

#endif