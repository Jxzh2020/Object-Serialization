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
        /*
        static size_t writebytes(const Seel&, char* buf);
        static size_t getbytes(const Seel&);
        */
        int32_t readbin(Seel& parsel);

        static const bool in = true;
        static const bool out = false;
    private:
        std::fstream fs;
        //char *buf;
};


int32_t Buffer::writebin(const Seel& parsel){
    /*
    char tmp = (int)parsel.return_type;
    fs.write(&tmp,sizeof(char));
    fs.write((char*)&parsel.meta_num,sizeof(int32_t)+sizeof(size_t));
    fs.write(parsel.data_,parsel.meta_num*parsel.atom_size);
    return sizeof(char)+sizeof(int32_t)+sizeof(size_t)+parsel.meta_num*parsel.atom_size;
    */
    char *buf = new char[parsel.getbytes()];
    parsel.writebytes(buf);
    fs.write(buf,parsel.getbytes());
    return parsel.getbytes();
}
/*
size_t Buffer::writebytes(const Seel& parsel, char* buf){
    int step = 0;
    char tmp = (int)parsel.return_type;
    // type byte
    memcpy(buf+step,&tmp,sizeof(char));
    step+=sizeof(char);
    //
    memcpy(buf+step,(char*)&parsel.meta_num,sizeof(int32_t)+sizeof(size_t));
    step+=sizeof(int32_t)+sizeof(size_t);
    //
    if(parsel.return_type<= STRING){
        memcpy(buf+step,parsel.data_,parsel.meta_num*parsel.atom_size);
        step+=parsel.meta_num*parsel.atom_size;
    }
        
    else{
        memcpy(buf+step,parsel.data_,parsel.atom_size);
        step+=parsel.atom_size;
    }
        
    return step;
}
size_t Buffer::getbytes(const Seel& parsel){
    if(parsel.return_type<=STRING)
        return sizeof(char)+sizeof(int32_t)+sizeof(size_t)+parsel.meta_num*parsel.atom_size;
    else
        return sizeof(char)+sizeof(int32_t)+sizeof(size_t)+parsel.atom_size;
}
*/
int32_t Buffer::readbin(Seel& parsel){
    /*
    char tmp;
    int32_t meta_num;
    size_t atom_size;
    size_t total;
    fs.read(&tmp,sizeof(char));

    if(parsel.return_type != (int)tmp)
        throw "bad type";

    fs.read((char *)&meta_num,sizeof(int32_t)+sizeof(size_t));
    if(parsel.return_type==STRING)
        total = meta_num*atom_size;
        
    else
        total = atom_size;
    parsel.data_ = new char[total];
    parsel.meta_num = meta_num;
    parsel.atom_size = atom_size;
    std::cout << meta_num << " and " << atom_size << std::endl;
    fs.read(parsel.data_,total);
    return sizeof(char)+sizeof(int32_t)+sizeof(size_t)+total;
}   */
    char tmp;
    int32_t meta_num;
    size_t atom_size;
    size_t total = 0;
    char* buf;
    fs.read(&tmp,sizeof(char));
    fs.read((char *)&meta_num,sizeof(int32_t));
    fs.read((char*)&atom_size,sizeof(size_t));
    if(parsel.return_type==STRING)
        total = meta_num*atom_size+sizeof(char)+sizeof(int32_t)+sizeof(size_t);
        
    else
        total = atom_size+sizeof(char)+sizeof(int32_t)+sizeof(size_t);
    std::cout << "before " << total <<" " << meta_num << " "<< atom_size << std::endl;
    buf = new char[(int)total];
    std::cout << "after" << std::endl;
    fs.seekg(0,std::ios::beg);
    fs.read(buf,total);
    parsel.deserialize_frombytes(buf);
    return total;
}

#endif