#include "include/arrays_strings/oneaway.h"
#include <gtest/gtest.h>
#include <string>

using algorithm::one_edit_away;

TEST( ONE_AWAY, SIMPLE_REMOVE ) {
    ASSERT_TRUE( one_edit_away( "pales", "pale" ) );
}

TEST( ONE_AWAY, SIMPLE_INSERT ) {
    ASSERT_TRUE( one_edit_away( "ple", "pale" ) );
}

TEST( ONE_AWAY, SIMPLE_REPLACE ) {
    ASSERT_TRUE( one_edit_away( "pale", "bale" ) );
}