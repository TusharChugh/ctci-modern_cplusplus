#include "include/trees_graphs/random_node.h"
#include <gtest/gtest.h>

TEST( RANDOM_NODE, DEMO ) {
    algorithm::bst<int> tree = {50, 40, 60, 30, 45, 55, 70, 20, 35};
    ASSERT_TRUE( tree.find( *( algorithm::get_random_node( tree ) ) ) != tree.end() );
}