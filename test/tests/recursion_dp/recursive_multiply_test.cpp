#include "include/recursion_dp/recursive_multiply.h"
#include <gtest/gtest.h>

TEST( RECURSIVE_MULTIPLY, TWO_TIMES_FIVE ) {
    ASSERT_EQ( 10, algorithm::recursive_multiply( 2, 5 ) );
}

TEST( RECURSIVE_MULTIPLY, EIGHT_TIMES_SEVEN ) {
    ASSERT_EQ( 56, algorithm::recursive_multiply( 8, 7 ) );
}

TEST( RECURSIVE_MULTIPLY, SEVEN_TIMES_EIGHT ) {
    ASSERT_EQ( 56, algorithm::recursive_multiply( 7, 8 ) );
}

TEST( RECURSIVE_MULTIPLY, TEN_TIMES_TEN ) {
    ASSERT_EQ( 100, algorithm::recursive_multiply( 10, 10 ) );
}

TEST( RECURSIVE_MULTIPLY, THREE_TIMES_ONE ) {
    ASSERT_EQ( 3, algorithm::recursive_multiply( 3, 1 ) );
}

TEST( RECURSIVE_MULTIPLY, FOUR_TIMES_ZERO ) {
    ASSERT_EQ( 0, algorithm::recursive_multiply( 4, 0 ) );
}

TEST( RECURSIVE_MULTIPLY, FIVE_TIMES_NINE ) {
    ASSERT_EQ( 45, algorithm::recursive_multiply( 5, 9 ) );
}

TEST( RECURSIVE_MULTIPLY, HUNDRED_TIMES_THOUSAND ) {
    ASSERT_EQ( 100000, algorithm::recursive_multiply( 100, 1000 ) );
}

TEST( RECURSIVE_MULTIPLY, ZERO_TIMES_THOUSAND ) {
    ASSERT_EQ( 0, algorithm::recursive_multiply( 0, 1000 ) );
}

TEST( RECURSIVE_MULTIPLY, ZERO_TIMES_ZERO ) {
    ASSERT_EQ( 0, algorithm::recursive_multiply( 0, 0 ) );
}