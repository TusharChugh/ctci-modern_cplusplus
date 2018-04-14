#include "include/arrays_strings/check_permutation.h"
#include <gtest/gtest.h>
#include <string>

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
    ASSERT_TRUE( check_permutation_count( "abc", "bac" ) );
}

TEST( CHECK_PERMUTATION, SIMPLE_NOT_PERMUTATION_MAP ) {
    ASSERT_FALSE( check_permutation_count( "abc", "bad" ) );
}

TEST( CHECK_PERMUTATION, UNEQUAL_LENGTH_MAP ) {
    ASSERT_FALSE( check_permutation_count( "abc", "abcd" ) );
}

TEST( CHECK_PERMUTATION, ALREADY_SORTED_MAP ) {
    ASSERT_TRUE( check_permutation_count( "abcd", "abcd" ) );
}