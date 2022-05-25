#include <utility>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <fstream>
#include <iostream>
#include <type_traits>
char se_open_er[] = "Serialization Open File Failed"; 
char de_open_er[] = "Deserialization Open File Failed";
/**
 * @brief std::is_arithmetic contains:
 *          bool:        true
 *          int:         true
 *          int const:   true
 *          float:       true
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
    
    char tmp;
    unsigned int size;
    std::ofstream ofs;
    T src = src_;
    ofs.open(file,std::ios::out);
    if(!ofs)
        throw se_open_er;
    if(std::is_arithmetic<T>::value){
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
    else if(std::is_same<T,std::string>::value){
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
    else{
        ;
    }
    return true;
    // const char get_type(T)
    /*
    switch(get_type(T)){
        case 0: // bool char 
            break;
        case 1: // int
            break;
        case 2: // float
            break;
        case 3: // string
            break;
        case 4: // string
            break;
        case 5: // string
            break;
        case 6: // string
            break;
        case 7: // string
            break;
        case 8: // string
            break;
    }
    */
}

template <class T>
bool deserialize(T& des, const std::string& file){
    char tmp;
    unsigned int size;
    std::ifstream ifs;
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
            char* k = new char[size];
            ifs.read(k,size);
            des = k;
            delete[] k;
            ifs.close();
            break;
    }

    return true;
}