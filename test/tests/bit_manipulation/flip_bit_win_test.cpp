#include <bit_manipulation/flip_bit_win.h>
#include <gtest/gtest.h>

#include <bitset>
#include <iostream>

TEST( FLIP_BIT_WIN, FIRST_SIXTEEN ) {
    std::vector<int> expected_outputs = {1, 2, 2, 3, 2, 3, 3, 4, 2, 2, 3, 4, 3, 4, 4, 5};

    int input_value = 0;
    for ( const auto& expected_output : expected_outputs )
        ASSERT_EQ( expected_output, algorithm::flip_bit_win( input_value++ ) );
}

TEST( FLIP_BIT_WIN, DEMO_TEST ) {
    ASSERT_EQ( 8, algorithm::flip_bit_win( 1775 ) );
}

TEST( FLIP_BIT_WIN, ZERO_TEST ) {
    ASSERT_EQ( 1, algorithm::flip_bit_win( 0 ) );
}

TEST( FLIP_BIT_WIN, MIN_MAX_TEST ) {
    ASSERT_EQ( 2, algorithm::flip_bit_win( INT_MIN ) );
    ASSERT_EQ( sizeof( int ) * 8, algorithm::flip_bit_win( INT_MAX ) );
}

TEST( FLIP_BIT_WIN, NEGATIVE_TEST ) {
    ASSERT_EQ( 32, algorithm::flip_bit_win( -1 ) );
    ASSERT_EQ( 22, algorithm::flip_bit_win( -1775 ) );
}