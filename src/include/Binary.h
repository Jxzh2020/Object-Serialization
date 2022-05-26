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
        Seel data(src_);
        std::cout << data.return_type << "and " << data.atom_size << std::endl;
        //return 0;
        buf.writebin(data);
        int mm = 32;
        char p = 'p';
        float ll = 1;
        bool bl = true;
        /*
        std::vector<int> jk(1);
        jk[0] = 99;
        buf.writebin(Seel(mm));
        buf.writebin(Seel(p));
        buf.writebin(Seel(ll));
        buf.writebin(Seel(bl));
        buf.writebin(Seel(jk));
        */
        
        return true;
    }

    template <class T>
    bool deserialize(T& des, const std::string& file){
        Buffer buf(file,Buffer::in);
        Seel des_(des);
        buf.readbin(des_);
        des_.wb(des);
        return true;
    }
}

#endif