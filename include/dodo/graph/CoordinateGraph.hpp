#pragma once


#include <boost/graph/properties.hpp>
#include <boost/pending/property.hpp>

#include "dodo/graph/SimpleBGL.hpp"
#include "dodo/utility/tree_id.hpp"

namespace dodo
{
namespace graph
{

    class CoordinateGraph :
        public graph::SimpleBGL<
            boost::no_property,
            boost::property<
                boost::edge_index_t,
                std::size_t
            >
        >
    {
    public:
        using SBGL = graph::SimpleBGL<
            boost::no_property,
            boost::property<
                boost::edge_index_t,
                std::size_t
            >
        >;
        using VertexID = SBGL::VertexID;

        CoordinateGraph() = default;


        CoordinateGraph( std::size_t nVertices ) :
            SBGL( nVertices )
        { }

    };


} /* graph */
} /* dodo */
