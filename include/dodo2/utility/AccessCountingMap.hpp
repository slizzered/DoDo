

#pragma once


#include <map>
#include <iostream>


namespace dodo
{
namespace utility
{
    template< typename T_Key, typename T_Value >
    class AccessCountingMap :
    public std::map<
            T_Key,
            T_Value
    > {
    public:
        size_t accesses = 0;
        T_Value& operator[](T_Key k)
        {
            //std::cout << "accessing " << k << std::endl;
            ++accesses;
            return std::map<T_Key,T_Value>::operator[](k);
        }

    };

}
}
