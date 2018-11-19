#include <arrays_strings/oneaway.h>
#include <gtest/gtest.h>

using algorithm::one_edit_away;
using algorithm::one_edit_away2;

TEST( ONE_AWAY, SIMPLE_REMOVE ) {
    ASSERT_TRUE( one_edit_away( "pales", "pale" ) );
}

TEST( ONE_AWAY, SIMPLE_INSERT ) {
    ASSERT_TRUE( one_edit_away( "ple", "pale" ) );
}

TEST( ONE_AWAY, SIMPLE_REPLACE ) {
    ASSERT_TRUE( one_edit_away( "pale", "bale" ) );
}

//Jesh
TEST( ONE_AWAY, SIMPLE_REPLACE2 ) {
    ASSERT_FALSE( one_edit_away( "pale", "baKe" ) );
}

TEST( ONE_AWAY2, SIMPLE_REMOVE ) {
    ASSERT_TRUE( one_edit_away2( "pales", "pale" ) );
}

TEST( ONE_AWAY2, SIMPLE_INSERT ) {
    ASSERT_TRUE( one_edit_away2( "ple", "pale" ) );
}

TEST( ONE_AWAY2, SIMPLE_REPLACE ) {
    ASSERT_TRUE( one_edit_away2( "pale", "bale" ) );
}

//Jesh
TEST( ONE_AWAY2, SIMPLE_REPLACE2 ) {
    ASSERT_FALSE( one_edit_away2( "pale", "baKe" ) );
}