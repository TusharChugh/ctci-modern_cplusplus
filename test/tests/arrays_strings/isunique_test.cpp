#include "include/arrays_strings/isunique.h"
#include <gtest/gtest.h>
#include <string>

using algorithm::isUnique_hash;

TEST( IS_UNIQUE, HASH_NO_DUPLICATES ) {
    ASSERT_TRUE( isUnique_hash( "abcd" ) );
}

TEST( IS_UNIQUE, HASH_HAS_DUPLICATES ) {
    ASSERT_FALSE( isUnique_hash( "abcda" ) );
}

TEST( IS_UNIQUE, HASH_ONLYNUMS_UNIQUE ) {
    ASSERT_TRUE( isUnique_hash( "1234" ) );
}

TEST( IS_UNIQUE, HASH_ONLYNUMS_NOT_UNIQUE ) {
    ASSERT_FALSE( isUnique_hash( "123454" ) );
}

TEST( IS_UNIQUE, HASH_ALPHANUM_NOT_UNIQUE ) {
    ASSERT_FALSE( isUnique_hash( "abc123454" ) );
}

TEST( IS_UNIQUE, HASH_ALPHANUM_UNIQUE ) {
    ASSERT_TRUE( isUnique_hash( "abc12345" ) );
}

TEST( IS_UNIQUE, EMPTY_STRING ) {
    ASSERT_TRUE( isUnique_hash( "" ) );
}

TEST( IS_UNIQUE, LVALUE_UNIQUE ) {
    std::string input = "abc";
    ASSERT_TRUE( isUnique_hash( input ) );
}

TEST( IS_UNIQUE, LVALUE_NOT_UNIQUE ) {
    std::string input = "abca";
    ASSERT_FALSE( isUnique_hash( input ) );
}

TEST( IS_UNIQUE, GREATER_128 ) {
    std::string input( 150, 'a' );
    ASSERT_FALSE( isUnique_hash( input ) );
}