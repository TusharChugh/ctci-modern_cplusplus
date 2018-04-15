#include "include/arrays_strings/palindrome_permutation.h"
#include <gtest/gtest.h>
#include <string>

TEST( PALINDROME_PERMUTATION, EMPTY_STRING ) {
    ASSERT_TRUE( is_palindrom_permutation( "" ) );
}

TEST( PALINDROME_PERMUTATION, ONE_CHAR ) {
    ASSERT_TRUE( is_palindrom_permutation( "a" ) );
}

TEST( PALINDROME_PERMUTATION, SIMPLE_ODD ) {
    ASSERT_TRUE( is_palindrom_permutation( "aba" ) );
}

TEST( PALINDROME_PERMUTATION, SIMPLE_EVEN ) {
    ASSERT_TRUE( is_palindrom_permutation( "abba" ) );
}

TEST( PALINDROME_PERMUTATION, NOT_IN_ORDER ) {
    ASSERT_TRUE( is_palindrom_permutation( "abbackcddffhhggk" ) );
}

TEST( PALINDROME_PERMUTATION, SIMPLE_ODD_FALSE ) {
    ASSERT_FALSE( is_palindrom_permutation( "ab" ) );
}

TEST( PALINDROME_PERMUTATION, SIMPLE_EVEN_FALSE ) {
    ASSERT_FALSE( is_palindrom_permutation( "abbacd" ) );
}

TEST( PALINDROME_PERMUTATION, NOT_IN_ORDER_FALSE ) {
    ASSERT_FALSE( is_palindrom_permutation( "abbckcdffhhggk" ) );
}

TEST( PALINDROME_PERMUTATION, UPPER_CASE ) {
    ASSERT_ANY_THROW( is_palindrom_permutation( "Abc" ) );
}
