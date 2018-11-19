#include <bit_manipulation/binary_string.h>
#include <gtest/gtest.h>

TEST( BINARY_STRING, DEMO_TEST ) {
    ASSERT_EQ( "1", algorithm::binary_string( 0.5 ) );
    ASSERT_EQ( "101", algorithm::binary_string( 0.625 ) );
    ASSERT_EQ( "11", algorithm::binary_string( 0.750 ) );
    ASSERT_EQ( "111", algorithm::binary_string( 0.875 ) );
}

TEST( BINARY_STRING, ERROR_TEST ) {
    ASSERT_EQ( "ERROR", algorithm::binary_string( 0 ) );
    ASSERT_EQ( "ERROR", algorithm::binary_string( 1 ) );
    ASSERT_EQ( "ERROR", algorithm::binary_string( -1 ) );
    ASSERT_EQ( "ERROR", algorithm::binary_string( 10 ) );
    ASSERT_EQ( "ERROR", algorithm::binary_string( -10 ) );
}