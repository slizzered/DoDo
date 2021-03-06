#pragma once

#include <string>

namespace dodo{
namespace model{
namespace routine{

    // alternatively: store the vertex IDs of data domain
    // -> less memory and probably faster, but not as abstract
    //    also more complicated if individual data items move
    template<typename T_Direction>
    class Port
    {
    public:
        std::string domain;
        T_Direction direction;
        unsigned padding;

        Port(
            std::string pDomain,
            T_Direction pDirection
        ) :
            domain{ pDomain },
            direction{ pDirection },
            padding{ 0u }
        {}

    };


} /* routine */
} /* model */
} /* dodo */


