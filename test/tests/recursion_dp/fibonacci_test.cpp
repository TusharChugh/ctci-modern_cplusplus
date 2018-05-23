#include "include/recursion_dp/fibonacci.h"
#include <gtest/gtest.h>

using algorithm::fib_recurssive;
using algorithm::fib_memoize_full;
using algorithm::fib_memoize_iterative;

TEST( FIBONACCI, SIMPLE_RECURSSION_TEST ) {
    ASSERT_EQ( 0, fib_recurssive( 0 ) );
    ASSERT_EQ( 1, fib_recurssive( 1 ) );
    ASSERT_EQ( 1, fib_recurssive( 2 ) );
    ASSERT_EQ( 2, fib_recurssive( 3 ) );
    ASSERT_EQ( 3, fib_recurssive( 4 ) );
    ASSERT_EQ( 5, fib_recurssive( 5 ) );
    ASSERT_EQ( 8, fib_recurssive( 6 ) );
    ASSERT_EQ( 13, fib_recurssive( 7 ) );
    ASSERT_EQ( 21, fib_recurssive( 8 ) );
}

TEST( FIBONACCI, SIMPLE_MEMOIZATION_TEST ) {
    ASSERT_EQ( 0, fib_memoize_full( 0 ) );
    ASSERT_EQ( 1, fib_memoize_full( 1 ) );
    ASSERT_EQ( 1, fib_memoize_full( 2 ) );
    ASSERT_EQ( 2, fib_memoize_full( 3 ) );
    ASSERT_EQ( 3, fib_memoize_full( 4 ) );
    ASSERT_EQ( 5, fib_memoize_full( 5 ) );
    ASSERT_EQ( 8, fib_memoize_full( 6 ) );
    ASSERT_EQ( 13, fib_memoize_full( 7 ) );
    ASSERT_EQ( 21, fib_memoize_full( 8 ) );
}

TEST( FIBONACCI, SIMPLE_ITERATIVE_TEST ) {
    ASSERT_EQ( 0, fib_memoize_iterative( 0 ) );
    ASSERT_EQ( 1, fib_memoize_iterative( 1 ) );
    ASSERT_EQ( 1, fib_memoize_iterative( 2 ) );
    ASSERT_EQ( 2, fib_memoize_iterative( 3 ) );
    ASSERT_EQ( 3, fib_memoize_iterative( 4 ) );
    ASSERT_EQ( 5, fib_memoize_iterative( 5 ) );
    ASSERT_EQ( 8, fib_memoize_iterative( 6 ) );
    ASSERT_EQ( 13, fib_memoize_iterative( 7 ) );
    ASSERT_EQ( 21, fib_memoize_iterative( 8 ) );
}

