#include <arrays_strings/check_permutation.h>
#include <gtest/gtest.h>
#include <string>

using algorithm::check_permutation_arraycount;
using algorithm::check_permutation_map;
using algorithm::check_permutation_sort;

TEST( CHECK_PERMUTATION, SIMPLE_PERMUTATION ) {
    ASSERT_TRUE( check_permutation_sort( "abc", "bac" ) );
}

TEST( CHECK_PERMUTATION, SIMPLE_NOT_PERMUTATION ) {
    ASSERT_FALSE( check_permutation_sort( "abc", "bad" ) );
}

TEST( CHECK_PERMUTATION, UNEQUAL_LENGTH ) {
    ASSERT_FALSE( check_permutation_sort( "abc", "abcd" ) );
}

TEST( CHECK_PERMUTATION, ALREADY_SORTED ) {
    ASSERT_TRUE( check_permutation_sort( "abcd", "abcd" ) );
}

TEST( CHECK_PERMUTATION, SIMPLE_PERMUTATION_MAP ) {
    ASSERT_TRUE( check_permutation_map( "abc", "bac" ) );
}

TEST( CHECK_PERMUTATION, SIMPLE_NOT_PERMUTATION_MAP ) {
    ASSERT_FALSE( check_permutation_map( "abc", "bad" ) );
}

TEST( CHECK_PERMUTATION, UNEQUAL_LENGTH_MAP ) {
    ASSERT_FALSE( check_permutation_map( "abc", "abcd" ) );
}

TEST( CHECK_PERMUTATION, ALREADY_SORTED_MAP ) {
    ASSERT_TRUE( check_permutation_map( "abcd", "abcd" ) );
}

TEST( CHECK_PERMUTATION, SIMPLE_PERMUTATION_ARRAY ) {
    ASSERT_TRUE( check_permutation_arraycount( "abc", "bac" ) );
}

TEST( CHECK_PERMUTATION, SIMPLE_NOT_PERMUTATION_ARRAY ) {
    ASSERT_FALSE( check_permutation_arraycount( "abc", "bad" ) );
}

TEST( CHECK_PERMUTATION, UNEQUAL_LENGTH_ARRAY ) {
    ASSERT_FALSE( check_permutation_arraycount( "abc", "abcd" ) );
}

TEST( CHECK_PERMUTATION, ALREADY_SORTED_ARRAY ) {
    ASSERT_TRUE( check_permutation_arraycount( "abcd", "abcd" ) );
}