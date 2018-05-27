#include <gtest/gtest.h>
#include "include/trees_graphs/paths_sum.h"

TEST( PATH_SUM, ZERO ) {
    algorithm::bst<int> tree = {10, 5, 13, 3, 2, 11, 3, -1, 1};
    ASSERT_EQ( 0, algorithm::path_with_sum_naive( tree, 40 ) );
}

TEST( PATH_SUM, ZERO_VALUE ) {
    algorithm::bst<int> tree = {10, 5, 13, 3, 2, 11, 3, 1};
    ASSERT_EQ( 0, algorithm::path_with_sum_naive( tree, 0 ) );
}

TEST( PATH_SUM, ONE ) {
    algorithm::bst<int> tree = {10, 5, 13, 3, 2, 11, 3, -1, 1};
    ASSERT_EQ( 1, algorithm::path_with_sum_naive( tree, 8 ) );
}

TEST( PATH_SUM, TWO ) {
    algorithm::bst<int> tree = {10, 5, 11, 3, 2, 1, 3};
    ASSERT_EQ( 2, algorithm::path_with_sum_naive( tree, 21 ) );
}

TEST( PATH_SUM, THREE ) {
    algorithm::bst<int> tree = {10, 5, 11, 3, 2, 1, 3, 0};
    ASSERT_EQ( 3, algorithm::path_with_sum_naive( tree, 21 ) );
}