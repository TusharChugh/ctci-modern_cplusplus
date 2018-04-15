#include "include/arrays_strings/urlify.h"
#include <gtest/gtest.h>
#include <string>

TEST( URLIFY, ONE_SPACE ) {
    std::string input  = "test test  ";
    std::string output = "test%20test";
    urlify_iterators( input, 9 );
    ASSERT_EQ( output, input );
}

TEST( URLIFY, TWO_SPACE_MIXED_CASES ) {
    std::string input  = "Mr John Smith    ";
    std::string output = "Mr%20John%20Smith";
    urlify_iterators( input, 13 );
    ASSERT_EQ( output, input );
}