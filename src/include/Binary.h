#ifndef BINARY_H
#define BINARY_H
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <fstream>
#include <iostream>
#include <type_traits>
#include "Buffer.h"
#include "Typefigure.h"
#include "Seel.h"

namespace binary{
    const char se_open_er[] = "Serialization Open File Failed"; 
    const char de_open_er[] = "Deserialization Open File Failed";
    /**
     * @brief std::is_arithmetic contains:
     *          bool:        true   0
     *          int:         true   1
     *          int const:   true   2
     *          float:       true   3
     *          float const: true   
     *          char:        true
     *          char const:  true
     *        std::string
     * 
     *        STL containers :
     *          std::pair
     *          std::vector
     *          std::list
     *          std::set
     *          std::map
     * 
     */

    template <class T>
    bool serialize(const T&, const std::string&);
    template <class T>
    bool deserialize(T&, const std::string&);
    /*
    unsigned int serialize_xml(T&, const std::string& ,const std::string&);
    unsigned int deserialize_xml(T&, const std::string& ,const std::string&);
    */


    template <class T>
    bool serialize(const T& src_, const std::string& file){
        Buffer buf(file,Buffer::out);
        char tmp;
        unsigned int size;
        std::ofstream ofs;
        T src = src_;
        Seel<T> data(src_);
        std::cout << data.return_type << "and " << data.atom_size << std::endl;
        return 0;
        ofs.open(file,std::ios::out);
        if(!ofs)
            throw se_open_er;
        if(!is_valid_type<decltype(src_)>){
            std::cout << "Error type!" << std::endl;
            return false;
        }
        

        // atomic types
        if(is_valid_type<decltype(src_)> && is_valid_type<decltype(src_)> < STRING){
            //buf.writebin(src_);
            std::cout << "is arithmetic" << std::endl;
            //ofs.write("Content_",8);
            // if is arithmetic
            tmp = 0;
            ofs.write(&tmp,sizeof(char));
            // size
            tmp = sizeof(T);
            ofs.write(&tmp,sizeof(char));
            // content
            ofs.write((char*)&src,sizeof(T));
            //ofs.write("_ends",5);
            ofs.close();
        }

        //  complex types
        else{
            std::cout << "is string" << std::endl;
            //ofs.write("Content_",8);
            // is string
            tmp = 1;
            ofs.write(&tmp,sizeof(char));
            size = src.length()+1;
            // length
            ofs.write((char*)&size,sizeof(unsigned int));
            //content
            ofs.write(src.c_str(),size);
            //ofs.write("_ends",5);
            ofs.close();
        }
        /*
        else if(is_container<T>::id){
            // write type
            tmp = is_container<T>::id ;
            ofs.write(&tmp,sizeof(char));
            // write number of contents
            ;
            // write number of one content's consisters
            ;
            // write atomic elements
            ;
            //size = T.size()*SIZE[is_container];
        }
        else    // not supported type
            return false;
            */
        return true;
    }

    template <class T>
    bool deserialize(T& des, const std::string& file){
        char tmp;
        unsigned int size;
        std::ifstream ifs;
        char* k;
        ifs.open(file,std::ios::in);
        if(!ifs)
            throw de_open_er;
        ifs.read(&tmp,sizeof(char));
        switch(tmp){
            case 0: // is arithmetic
                ifs.read(&tmp,sizeof(char));
                ifs.read((char*)&des,tmp);
                ifs.close();
                break;
            case 1:
                ifs.read((char*)&size,sizeof(unsigned int));
                k = new char[size];
                ifs.read(k,size);
                des = k;
                delete[] k;
                ifs.close();
                break;
            case 3:
                ;
                break;
        }

        return true;
    }
}

#endif