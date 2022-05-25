#ifndef TYPEFIGURE_H
#define TYPEFIGURE_H
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <type_traits>
enum Type{
    OTHER,
    BOOL,
    INT,
    FLOAT,
    CHAR,
    STRING,
    PAIR,
    VECTOR,
    LIST,
    SET,
    MAP
    
};

template<typename T, typename... type>
struct _is_valid_type
{
    static const Type id = OTHER;
    
};

template<>
struct _is_valid_type<bool>
{
    static const Type id = BOOL;
    //static const int8_t size = 1;
};
template<>
struct _is_valid_type<int>
{
    static const Type id = INT;
    //static const int8_t size = 4;
};
template<>
struct _is_valid_type<float>
{
    static const Type id = FLOAT;
    //static const int8_t size = 4;
};
template<>
struct _is_valid_type<char>
{
    static const Type id = CHAR;
};
template<>
struct _is_valid_type<std::string>
{
    static const Type id = STRING;
};






template<typename T, typename... type>
struct _is_valid_type<std::pair<T,type...>>
{
    static const Type id = PAIR;
};

template<typename T, typename... type>
struct _is_valid_type<std::vector<T,type...>>
{
    static const Type id = VECTOR;
};

template<typename T, typename... type>
struct _is_valid_type<std::list<T,type...>>
{
    static const Type id = LIST;
};
template<typename T, typename... type>
struct _is_valid_type<std::set<T,type...>>
{
    static const Type id = SET;
};
template<typename T, typename... type>
struct _is_valid_type<std::map<T,type...>>
{
    static const Type id = MAP;
};


template<typename T,typename... Types>
constexpr Type is_valid_type = _is_valid_type<T, Types...>::id;


#endif