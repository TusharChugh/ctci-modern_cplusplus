#include "include/recursion_dp/power_set.h"
#include <gtest/gtest.h>

TEST( POWER_SET, EMPTY ) {
    std::vector<int> input;
    ASSERT_TRUE( algorithm::power_set( input ).empty() );
}

TEST( POWER_SET, EMPTY_DEFAULT_INIT ) {
    std::vector<int> input = {};
    ASSERT_TRUE( algorithm::power_set( input ).empty() );
}

TEST( POWER_SET, ONE_ELEMENTS ) {
    std::vector<int> input                        = {1};
    std::vector<std::vector<int>> expected_output = {{1}};
    ASSERT_EQ( expected_output, algorithm::power_set( input ) );
}

TEST( POWER_SET, TWO_ELEMENTS ) {
    std::vector<int> input                        = {1, 2};
    std::vector<std::vector<int>> expected_output = {{1}, {1, 2}, {2}};
    ASSERT_EQ( expected_output, algorithm::power_set( input ) );
}

TEST( POWER_SET, THREE_ELEMENTS ) {
    std::vector<int> input                        = {1, 2, 3};
    std::vector<std::vector<int>> expected_output = {{1},       {1, 2}, {2}, {1, 3},
                                                     {1, 2, 3}, {2, 3}, {3}};
    ASSERT_EQ( expected_output, algorithm::power_set( input ) );
}

TEST( POWER_SET, FOUR_ELEMENTS ) {
    std::vector<int> input                        = {1, 2, 3, 4};
    std::vector<std::vector<int>> expected_output = {
        {1},       {1, 2}, {2},       {1, 3},       {1, 2, 3}, {2, 3}, {3}, {1, 4},
        {1, 2, 4}, {2, 4}, {1, 3, 4}, {1, 2, 3, 4}, {2, 3, 4}, {3, 4}, {4}};

    ASSERT_EQ( expected_output, algorithm::power_set( input ) );
}