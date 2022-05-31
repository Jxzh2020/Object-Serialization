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
#include "Reflection.h"

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
     *          std::string
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
    template <class T>
    unsigned int serialize_xml(T&, const std::string& ,const std::string&);
    template <class T>
    unsigned int deserialize_xml(T&, const std::string& ,const std::string&);
    


    template <class T>
    bool serialize(const T& src_, const std::string& file){
        if(is_valid_type<T> == Type::OTHER && !is_user_defined<T>::ret)
            throw "Not valid type! at serialize()";

        Buffer buf(file,Buffer::out);

        Seel data(src_);
        buf.writebin(data);

        
        return true;
    }

/*
    template <typename T>
    bool serialize(const Packer<T>& src_, const std::string& file){
        if(is_valid_type<T> == Type::OTHER && !is_user_defined<T>::ret)
            throw "Not valid type!";

        Buffer buf(file,Buffer::out);

        Seel data(src_);

        return true;
    }
*/

    template <class T>
    bool deserialize(T& des, const std::string& file){
        if(is_valid_type<T> == Type::OTHER && !is_user_defined<T>::ret)
            throw "Not valid type!";
        Buffer buf(file,Buffer::in);
        std::cout << "Seel not completed!!" <<std::endl;
        Seel des_(des);
        std::cout << "readbin not completed!!" <<std::endl;
        buf.readbin(des_);
        std::cout << "readbin completed!!" <<std::endl;
        des_.writeback(des);
        return true;
    }

    // TODO xml
    template <class T>
    unsigned int serialize_xml(T&, const std::string& ,const std::string&){
        return 0;
    }

    // TODO xml
    template <class T>
    unsigned int deserialize_xml(T&, const std::string& ,const std::string&){
        return 0;
    }
}

#endif