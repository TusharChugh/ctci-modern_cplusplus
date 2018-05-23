#include "include/recursion_dp/magic_index.h"
#include <gtest/gtest.h>

TEST( MAGIC_INDEX, MIDDLE ) {
    std::vector<int> input = {-1, 1, 0, 1, 2, 5, 10, 12, 14, 16, 100};
    ASSERT_EQ( 5, algorithm::magic_index( input ) );
}

TEST( MAGIC_INDEX, FIRST ) {
    std::vector<int> input = {0, 2, 5, 10, 12, 14, 16, 100};
    ASSERT_EQ( 0, algorithm::magic_index( input ) );
}

TEST( MAGIC_INDEX, LAST ) {
    std::vector<int> input = {-1, 1, 0, 1, 2, 3, 4, 5, 7, 8, 10};
    ASSERT_EQ( 10, algorithm::magic_index( input ) );
}

TEST( MAGIC_INDEX, EMPTY ) {
    std::vector<int> input;
    ASSERT_EQ( 0, algorithm::magic_index( input ) );
}

TEST( MAGIC_INDEX, LEFT_SIDE ) {
    std::vector<int> input = {-1, 1, 0, 1, 2, 5, 10, 12, 14, 16, 100, 500, 700, 2000};
    ASSERT_EQ( 5, algorithm::magic_index( input ) );
}

TEST( MAGIC_INDEX, RIGHT_SIDE ) {
    std::vector<int> input = {-1, 1, 0, 1, 2, 3, 6, 8, 10};
    ASSERT_EQ( 6, algorithm::magic_index( input ) );
}