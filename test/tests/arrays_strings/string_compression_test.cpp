#include "include/arrays_strings/string_compression.h"
#include <gtest/gtest.h>
#include <string>

using algorithm::compress;

TEST( STRING_COMPRESSION, EMPTY_STRING ) {
    ASSERT_EQ( "", compress( "" ) );
}

TEST( STRING_COMPRESSION, THREE_CHARS ) {
    ASSERT_EQ( "a2b1c5a3", compress( "aabcccccaaa" ) );
}

TEST( STRING_COMPRESSION, EQUAL_LENGTH ) {
    ASSERT_EQ( "aabbcc", compress( "aabbcc" ) );
}

TEST( STRING_COMPRESSION, LESS_LENGTH ) {
    ASSERT_EQ( "aabbcc", compress( "aabbcc" ) );
}

TEST( STRING_COMPRESSION, SINGLE_CHAR ) {
    ASSERT_EQ( "a", compress( "a" ) );
}

TEST( STRING_COMPRESSION, SINGLE_CHAR_MULTIPLE_TIMES ) {
    ASSERT_EQ( "a5", compress( "aaaaa" ) );
}