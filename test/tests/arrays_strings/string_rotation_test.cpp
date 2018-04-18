#include "include/arrays_strings/string_rotation.h"
#include <gtest/gtest.h>
#include <string>

using algorithm::is_rotation;

TEST( STRING_ROTATION, BOTH_EMPTY_STRING ) {
    ASSERT_FALSE( is_rotation( "", "" ) );
}

TEST( STRING_ROTATION, FIRST_EMPTY_STRING ) {
    ASSERT_FALSE( is_rotation( "", "abc" ) );
}

TEST( STRING_ROTATION, SECOND_EMPTY_STRING ) {
    ASSERT_FALSE( is_rotation( "abc", "" ) );
}

TEST( STRING_ROTATION, UNEQUAL_LENGTH ) {
    ASSERT_FALSE( is_rotation( "abcd", "abc" ) );
}

TEST( STRING_ROTATION, EQUAL_STRING ) {
    ASSERT_TRUE( is_rotation( "abc", "abc" ) );
}

TEST( STRING_ROTATION, ROTATED_STRING ) {
    ASSERT_TRUE( is_rotation( "waterbottle", "erbottlewat" ) );
}