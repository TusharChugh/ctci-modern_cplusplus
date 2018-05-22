#include "include/trees_graphs/adj_list_graph.h"
#include <gtest/gtest.h>

TEST( ADJ_LIST_GRPAH, DIRECTED_DEMO ) {
    algorithm::adj_list_graph<true> input_graph( 5 );

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

TEST( ADJ_LIST_GRPAH, UNDIRECTED_DEMO ) {
    algorithm::adj_list_graph<false> input_graph( 5 );

    input_graph.add_edge( 0, 1 );
    input_graph.add_edge( 0, 2 );
    input_graph.add_edge( 1, 3 );
    input_graph.add_edge( 1, 4 );

    std::forward_list<int> out0 = {2, 1};
    std::forward_list<int> out1 = {4, 3, 0};
    std::forward_list<int> out2 = {0};
    std::forward_list<int> out3 = {1};
    std::forward_list<int> out4 = {1};
    ASSERT_EQ( out0, input_graph.adjacent_vertices( 0 ) );
    ASSERT_EQ( out1, input_graph.adjacent_vertices( 1 ) );
    ASSERT_EQ( out2, input_graph.adjacent_vertices( 2 ) );
    ASSERT_EQ( out3, input_graph.adjacent_vertices( 3 ) );
    ASSERT_EQ( out4, input_graph.adjacent_vertices( 4 ) );
}