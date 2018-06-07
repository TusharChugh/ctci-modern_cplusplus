#include "include/recursion_dp/robot_grid.h"
#include <gtest/gtest.h>

#include <iostream>

TEST( ROBOT_GRID, DEMO ) {
    algorithm::graph_grid graph( 5, 5 );
    auto path = algorithm::find_path( graph, std::make_pair( 1, 1 ), std::make_pair( 5, 5 ) );
    std::vector<algorithm::Location> expected_path = {{1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5},
                                                      {2, 5}, {3, 5}, {4, 5}, {5, 5}};
    ASSERT_EQ( 9, path.size() );
    ASSERT_EQ( expected_path, path );
}