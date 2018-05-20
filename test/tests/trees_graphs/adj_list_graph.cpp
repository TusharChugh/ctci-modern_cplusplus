#include "include/trees_graphs/adj_list_graph.h"
#include <gtest/gtest.h>

TEST( ADJ_LIST_GRPAH, DEMO ) {
    algorithm::adj_list_graph input_graph( 5 );

    input_graph.add_edge( 0, 1 );
    input_graph.add_edge( 0, 2 );
    input_graph.add_edge( 1, 3 );
    input_graph.add_edge( 1, 4 );

    std::forward_list<int> out0 = {2, 1};
    std::forward_list<int> out1 = {4, 3};
    std::forward_list<int> out2;
    ASSERT_EQ( out0, input_graph.adjacent_vertices( 0 ) );
    ASSERT_EQ( out1, input_graph.adjacent_vertices( 1 ) );
    ASSERT_EQ( out2, input_graph.adjacent_vertices( 2 ) );
    ASSERT_EQ( out2, input_graph.adjacent_vertices( 3 ) );
    ASSERT_EQ( out2, input_graph.adjacent_vertices( 4 ) );
}