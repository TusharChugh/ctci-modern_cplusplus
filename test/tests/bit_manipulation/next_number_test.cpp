#include <bit_manipulation/next_number.h>
#include <gtest/gtest.h>

TEST( NEXT_NUMBER, DEMO ) {
    ASSERT_EQ( 0b11011010001111, algorithm::next_number( 0b11011001111100 ) );
}

TEST( NEXT_NUMBER, FIRST_ELEVEN ) {
    std::vector<unsigned int> expected_outputs = {0, 2, 4, 5, 8, 6, 9, 11, 16, 10, 12, 13};

    unsigned int input_value = 0;
    for ( const auto& expected_output : expected_outputs ) {
        ASSERT_EQ( expected_output, algorithm::next_number( input_value++ ) );
    }
}