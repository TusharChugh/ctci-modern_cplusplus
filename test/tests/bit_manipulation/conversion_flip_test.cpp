#include <bit_manipulation/conversion_flip.h>
#include <gtest/gtest.h>

TEST( CONVERSION_FLIP, DEMO ) {
    ASSERT_EQ( 2, algorithm::flips_required_naive( 0b11101, 0b01111 ) );
    ASSERT_EQ( 2, algorithm::flips_required_shift( 0b11101, 0b01111 ) );
    ASSERT_EQ( 2, algorithm::flips_required_trick( 0b11101, 0b01111 ) );
}