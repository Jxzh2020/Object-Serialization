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

        
        int32_t writebin(const Seel&);
        int32_t readbin(Seel& parsel);

        static const bool in = true;
        static const bool out = false;
    private:
        std::fstream fs;
};


int32_t Buffer::writebin(const Seel& parsel){
    char tmp = (int)parsel.return_type;
    fs.write(&tmp,sizeof(char));
    fs.write((char*)&parsel.meta_num,sizeof(int32_t)+sizeof(size_t));
    fs.write(parsel.data_,parsel.meta_num*parsel.atom_size);
    return sizeof(char)+sizeof(int32_t)+sizeof(size_t)+parsel.meta_num*parsel.atom_size;
}
int32_t Buffer::readbin(Seel& parsel){
    char tmp;
    int32_t meta_num;
    size_t atom_size;
    fs.read(&tmp,sizeof(char));

    if(parsel.return_type != (int)tmp)
        throw "bad type";

    fs.read((char *)&meta_num,sizeof(int32_t)+sizeof(size_t));
    parsel.data_ = new char[meta_num*atom_size];
    parsel.meta_num = meta_num;
    parsel.atom_size = atom_size;
    std::cout << meta_num << " and " << atom_size << std::endl;
    fs.read(parsel.data_,parsel.meta_num*parsel.atom_size);
    return sizeof(char)+sizeof(int32_t)+sizeof(size_t)+parsel.meta_num*parsel.atom_size;
}

#endif