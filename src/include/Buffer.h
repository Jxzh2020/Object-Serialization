#ifndef BUFFER_H
#define BUFFER_H
#include <fstream>
#include <iostream>
#include <string>
#include <exception>
#include "Typefigure.h"
#include "Seel.h"

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
        ~Buffer(){
            fs.close();
        }

        template<typename T,typename... type>
        int32_t writebin(const Seel<T>&);

        static const bool in = true;
        static const bool out = false;
    private:
        std::fstream fs;
};

template<typename T,typename... type>
int32_t Buffer::writebin(const Seel<T>& parsel){
    char tmp = (int)parsel.return_type;
    fs.write(&tmp,sizeof(char));
    fs.write((char*)&parsel.meta_num,sizeof(int32_t)+sizeof(size_t));
    fs.write(parsel.data_,parsel.meta_num*parsel.atom_size);
    return sizeof(char)+sizeof(int32_t)+sizeof(size_t)+sizeof(T);
}

#endif