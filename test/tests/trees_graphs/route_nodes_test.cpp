#include <gtest/gtest.h>

#include "include/trees_graphs/adj_list_graph.h"
#include "include/trees_graphs/route_nodes.h"

TEST( ROUTE_NODES, DEMO ) {
    algorithm::adj_list_graph<true> input( 5 );

    input.add_edge( 0, 1 );
    input.add_edge( 0, 2 );
    input.add_edge( 1, 3 );
    input.add_edge( 1, 4 );

    ASSERT_TRUE( algorithm::route_between_nodes( input, 0, 1 ) );
    ASSERT_TRUE( algorithm::route_between_nodes( input, 0, 2 ) );
    ASSERT_TRUE( algorithm::route_between_nodes( input, 1, 3 ) );
    ASSERT_TRUE( algorithm::route_between_nodes( input, 1, 4 ) );

    ASSERT_TRUE( algorithm::route_between_nodes( input, 0, 0 ) );
    ASSERT_TRUE( algorithm::route_between_nodes( input, 1, 1 ) );
    ASSERT_TRUE( algorithm::route_between_nodes( input, 2, 2 ) );
    ASSERT_TRUE( algorithm::route_between_nodes( input, 3, 3 ) );
    ASSERT_TRUE( algorithm::route_between_nodes( input, 4, 4 ) );

    ASSERT_FALSE( algorithm::route_between_nodes( input, 0, 3 ) );
    ASSERT_FALSE( algorithm::route_between_nodes( input, 0, 4 ) );
    ASSERT_FALSE( algorithm::route_between_nodes( input, 1, 0 ) );
    ASSERT_FALSE( algorithm::route_between_nodes( input, 1, 2 ) );
}