#include <trees_graphs/graph_grid.h>
#include <gtest/gtest.h>

TEST( GRAPH_GRID, INIT_TEST ) {
    algorithm::graph_grid graph( 10, 10 );
    auto graph_size = graph.size();
    ASSERT_EQ( 10, graph_size.first );
    ASSERT_EQ( 10, graph_size.second );
}

TEST( GRAPH_GRID, LEFT_TEST ) {
    algorithm::graph_grid graph( 10, 10 );
    auto left = graph.left( std::make_pair( 1, 2 ) );
    ASSERT_EQ( 1, left.first );
    ASSERT_EQ( 1, left.second );
}

TEST( GRAPH_GRID, RIGHT_TEST ) {
    algorithm::graph_grid graph( 10, 10 );
    auto right = graph.right( std::make_pair( 1, 2 ) );
    ASSERT_EQ( 1, right.first );
    ASSERT_EQ( 3, right.second );
}

TEST( GRAPH_GRID, UP_TEST ) {
    algorithm::graph_grid graph( 10, 10 );
    auto up = graph.up( std::make_pair( 2, 2 ) );
    ASSERT_EQ( 1, up.first );
    ASSERT_EQ( 2, up.second );
}

TEST( GRAPH_GRID, DOWN_TEST ) {
    algorithm::graph_grid graph( 10, 10 );
    auto down = graph.down( std::make_pair( 1, 2 ) );
    ASSERT_EQ( 2, down.first );
    ASSERT_EQ( 2, down.second );
}

TEST( GRAPH_GRID, NEIGHBOUR_LEFT_TOP_TEST ) {
    algorithm::graph_grid graph( 10, 10 );
    auto neighbors = graph.neighbors( std::make_pair( 1, 1 ) );
    ASSERT_EQ( 2, neighbors.size() );
}

TEST( GRAPH_GRID, NEIGHBOUR_RIGHT_TOP_TEST ) {
    algorithm::graph_grid graph( 10, 10 );
    auto neighbors = graph.neighbors( std::make_pair( 1, 10 ) );
    ASSERT_EQ( 2, neighbors.size() );
}

TEST( GRAPH_GRID, NEIGHBOUR_LEFT_BOTTOM_TEST ) {
    algorithm::graph_grid graph( 10, 10 );
    auto neighbors = graph.neighbors( std::make_pair( 10, 1 ) );
    ASSERT_EQ( 2, neighbors.size() );
}

TEST( GRAPH_GRID, NEIGHBOUR_RIGHT_BOTTOM_TEST ) {
    algorithm::graph_grid graph( 10, 10 );
    auto neighbors = graph.neighbors( std::make_pair( 10, 10 ) );
    ASSERT_EQ( 2, neighbors.size() );
}

TEST( GRAPH_GRID, NEIGHBOUR_MIDDLE_TEST ) {
    algorithm::graph_grid graph( 10, 10 );
    auto neighbors = graph.neighbors( std::make_pair( 5, 5 ) );
    ASSERT_EQ( 4, neighbors.size() );
}