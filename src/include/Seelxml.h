#ifndef SEELXML_H
#define SEELXML_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <utility>
#include <map>

#include "../thirdparty/tinyxml2.h"
#include "Typefigure.h"
#include "Reflection.h"
#include "MACRO_EX.h"

using namespace tinyxml2;

#define XML_ATMOIC_CTOR         std::string name = std::to_string(key);                     \
                                name = tname + name;                                        \
                                XMLElement* sub_root = doc->NewElement(tname.c_str());       \
                                root->InsertEndChild(sub_root);                             \
                                sub_root->SetAttribute("value", data);                      \
                                key++;  return 1;

class Seelxml{
    public:
        template <typename T>
        Seelxml(XMLDocument* doc_,T& src, uint32_t step):doc(doc_),key(step){}
        ~Seelxml(){};
        
        template <typename T>
        int serialize(const T& src, XMLElement* root){
            return serialize_node(src, root);
        }

        template <typename T>
        XMLError deserialize(T& src, XMLElement* root){
            XMLElement * sub_root;
            /*
            if(is_user_defined<T>::ret)
                return deserialize_node(src, root);
            else{
                */
                sub_root = root->FirstChildElement();
                std::cout << "name is: " << sub_root->Name()<<std::endl;
                return deserialize_node(src, sub_root);
            //}
                
        }

    private:
        template <typename T>
        int serialize_node(const T& src, XMLElement* root);

        template <typename T>
        int serialize_node(const std::vector<T>& data, XMLElement* root){
            std::string tname = "std_vector_";
            std::string name = std::to_string(key++);
            name = tname + name;
            int step = 0;
            XMLElement* sub_root = doc->NewElement(tname.c_str());
            root->InsertEndChild(sub_root);
            for(auto& i : data){
                step+=serialize_node(i, sub_root);
            }
            key+=step;
            return step;
        }

        template <typename T>
        int serialize_node(const std::set<T>& data, XMLElement* root){
            std::string tname = "std_set_";
            std::string name = std::to_string(key++);
            name = tname + name;
            int step = 0;
            XMLElement* sub_root = doc->NewElement(tname.c_str());
            root->InsertEndChild(sub_root);
            for(auto& i : data){
                step+=serialize_node(i, sub_root);
            }
            key+=step;
            return step;
        }

        template <typename T>
        int serialize_node(const std::list<T>& data, XMLElement* root){
            std::string tname = "std_list_";
            std::string name = std::to_string(key++);
            name = tname + name;
            int step = 0;
            XMLElement* sub_root = doc->NewElement(tname.c_str());
            root->InsertEndChild(sub_root);
            for(auto& i : data){
                step+=serialize_node(i, sub_root);
            }
            key+=step;
            return step;
        }

        template <typename T, typename K>
        int serialize_node(const std::pair<T,K>& data, XMLElement* root){
            std::string tname = "std_pair_";
            std::string name = std::to_string(key++);
            name = tname + name;
            int step = 0;
            XMLElement* sub_root = doc->NewElement(tname.c_str());
            root->InsertEndChild(sub_root);
            step+=serialize_node(data.first,sub_root);
            step+=serialize_node(data.second,sub_root);

            key+=step;
            return step;
        }
        template <typename T, typename K>
        int serialize_node(const std::map<T,K>& data, XMLElement* root){
            std::string tname = "std_map_";
            std::string name = std::to_string(key++);
            name = tname + name;
            int step = 0;
            std::pair<T,K> temp;
            XMLElement* sub_root = doc->NewElement(tname.c_str());
            root->InsertEndChild(sub_root);
            for(auto& i : data){
                temp = i;
                step+=serialize_node(temp, sub_root);
                
            }
            key+=step;
            return step;
        }
        template <typename T>
        XMLError deserialize_node(T& src, XMLElement* root);

        template <typename T>
        XMLError deserialize_node(std::vector<T>& src, XMLElement* root){
            XMLElement* sub = root->FirstChildElement();
            T temp;
            src.clear();
            XMLError k;
            while(sub){
                k = deserialize_node(temp, sub);
                if(k != XML_SUCCESS)
                    return k;
                src.push_back(temp);
                sub = sub->NextSiblingElement();
            }
            return XML_SUCCESS;
        }
        template <typename T>
        XMLError deserialize_node(std::set<T>& src, XMLElement* root){
            XMLElement* sub = root->FirstChildElement();
            T temp;
            src.clear();
            XMLError k;
            while(sub){
                k = deserialize_node(temp, sub);
                if(k != XML_SUCCESS)
                    return k;
                src.insert(temp);
                sub = sub->NextSiblingElement();
            }
            return XML_SUCCESS;
        }
        template <typename T>
        XMLError deserialize_node(std::list<T>& src, XMLElement* root){
            XMLElement* sub = root->FirstChildElement();
            T temp;
            src.clear();
            XMLError k;
            while(sub){
                k = deserialize_node(temp, sub);
                if(k != XML_SUCCESS)
                    return k;
                src.push_back(temp);
                sub = sub->NextSiblingElement();
            }
            return XML_SUCCESS;
        }
        template <typename T, typename K>
        XMLError deserialize_node(std::pair<T,K>& src, XMLElement* root){
            XMLElement* sub = root->FirstChildElement();
            std::pair<T,K> temp;
            
            XMLError k;

            k = deserialize_node(temp.first, sub);
            if(k != XML_SUCCESS)
                return k;
            sub = sub->NextSiblingElement();
            k = deserialize_node(temp.second, sub);
            src = temp;

            return k;
        }
        template <typename T, typename K>
        XMLError deserialize_node(std::map<T,K>& src, XMLElement* root){
            std::pair<T,K> temp;
            XMLElement* sub = root->FirstChildElement();
            XMLError k;
            src.clear();
            while(sub){
                k = deserialize_node(temp, sub);
                if(k != XML_SUCCESS)
                    return k;
                src.insert(temp);
                sub = sub->NextSiblingElement();
            }
            return k;
        }



        XMLDocument* doc;
        uint32_t key;

};
template <typename T>
int Seelxml::serialize_node(const T& src, XMLElement* root){

    TypeInfo info = src._GETINFO();
    int meta_num = info.members;
    int step = 0;
    // TODO a copy that can be avoided
    T data = src;
    XMLElement* sub_root = doc->NewElement(info.name.c_str());
    root->InsertEndChild(sub_root);
    
    if(0 == meta_num)
        return step;
    step+=serialize_node(data.FUN(1),sub_root);

    if(1 == meta_num){
        key+=step;
        return step;

    }
        
        
    step+=serialize_node(data.FUN(2),sub_root);

    if(2 == meta_num)
        return step;
    step+=serialize_node(data.FUN(3),sub_root);

    if(3 == meta_num)
        return step;
    step+=serialize_node(data.FUN(4),sub_root);

    if(4 == meta_num)
        return step;
    step+=serialize_node(data.FUN(5),sub_root);

    if(5 == meta_num)
        return step;
    step+=serialize_node(data.FUN(6),sub_root);
    if(6 == meta_num)
        return step;
    step+=serialize_node(data.FUN(7),sub_root);
    if(7 == meta_num)
        return step;
    step+=serialize_node(data.FUN(8),sub_root);
    if(8 == meta_num)
        return step;
    step+=serialize_node(data.FUN(9),sub_root);
    if(9 == meta_num)
        return step;
    step+=serialize_node(data.FUN(10),sub_root);
    if(10 == meta_num)
        return step;
    step+=serialize_node(data.FUN(12),sub_root);
    if(11 == meta_num)
        return step;
    step+=serialize_node(data.FUN(12),sub_root);
    if(12 == meta_num)
        return step;
    step+=serialize_node(data.FUN(13),sub_root);
    if(13 == meta_num)
        return step;
    step+=serialize_node(data.FUN(14),sub_root);
    if(14 == meta_num)
        return step;
    step+=serialize_node(data.FUN(15),sub_root);
    if(15 == meta_num)
        return step;
    step+=serialize_node(data.FUN(16),sub_root);
    return step;
}

template <>
int Seelxml::serialize_node(const bool& data, XMLElement* root){std::string tname = "bool_"; XML_ATMOIC_CTOR}

template <>
int Seelxml::serialize_node(const char& data, XMLElement* root){std::string tname = "char_"; XML_ATMOIC_CTOR}

template <>
int Seelxml::serialize_node(const int& data, XMLElement* root){std::string tname = "int_"; XML_ATMOIC_CTOR}

template <>
int Seelxml::serialize_node(const float& data, XMLElement* root){std::string tname = "float_"; XML_ATMOIC_CTOR}

template <>
int Seelxml::serialize_node(const std::string& data, XMLElement* root){
    std::string tname = "string_"; 
    std::string name = std::to_string(key);
    name = tname + name;
    XMLElement* sub_root = doc->NewElement(tname.c_str());
    root->InsertEndChild(sub_root);
    sub_root->SetAttribute("value", data.c_str());
    key++;  
    return 1;
}

template <typename T>
XMLError Seelxml::deserialize_node(T& data, XMLElement* root){
    XMLElement * sub_root = root->FirstChildElement();
 
    int meta_num = data._GETINFO().members;
    XMLError L;

    // TODO a copy that can be avoided

    
    if(0 == meta_num)
        return XML_ERROR_EMPTY_DOCUMENT;
    L = deserialize_node(data.FUN(1),sub_root);

    if(1 == meta_num || L != XML_SUCCESS)
        return L;

    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(2),sub_root);

    if(2 == meta_num || L != XML_SUCCESS)
        return L;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(3),sub_root);

    if(3 == meta_num || L != XML_SUCCESS)
        return L ;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(4),sub_root);

    if(4 == meta_num || L != XML_SUCCESS)
        return L ;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(5),sub_root);

    if(5 == meta_num || L != XML_SUCCESS)
        return L ;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(6),sub_root);
    if(6 == meta_num || L != XML_SUCCESS)
        return L ;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(7),sub_root);
    if(7 == meta_num || L != XML_SUCCESS)
        return L ;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(8),sub_root);
    if(8 == meta_num || L != XML_SUCCESS)
        return L ;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(9),sub_root);
    if(9 == meta_num || L != XML_SUCCESS)
        return L ;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(10),sub_root);
    if(10 == meta_num || L != XML_SUCCESS)
        return L ;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(12),sub_root);
    if(11 == meta_num || L != XML_SUCCESS)
        return L ;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(12),sub_root);
    if(12 == meta_num || L != XML_SUCCESS)
        return L ;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(13),sub_root);
    if(13 == meta_num || L != XML_SUCCESS)
        return L;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(14),sub_root);
    if(14 == meta_num || L != XML_SUCCESS)
        return L;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(15),sub_root);
    if(15 == meta_num || L != XML_SUCCESS)
        return L;
    sub_root = sub_root->NextSiblingElement();
    L = deserialize_node(data.FUN(16),sub_root);
    return L;

}

template <>
XMLError Seelxml::deserialize_node(bool& src, XMLElement* root){
    return root->QueryBoolAttribute("value",&src);
}

template <>
XMLError Seelxml::deserialize_node(char& src, XMLElement* root){
    int des;
    XMLError res = root->QueryIntAttribute("value", &des);
    src = (char)des;
    return res;
}

template <>
XMLError Seelxml::deserialize_node(int& src, XMLElement* root){
    return root->QueryIntAttribute("value", &src);
}

template <>
XMLError Seelxml::deserialize_node(float& src, XMLElement* root){
    return root->QueryFloatAttribute("value", &src);
}

template <>
XMLError Seelxml::deserialize_node(std::string& src, XMLElement* root){
    char* buffer = nullptr;
    XMLError tmp = root->QueryStringAttribute("value", (const char **)&buffer);
    src = buffer;
    return tmp;
}






#endif // SEELXML_H