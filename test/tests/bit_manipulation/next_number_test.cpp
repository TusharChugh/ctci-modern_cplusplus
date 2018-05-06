#include "include/bit_manipulation/next_number.h"
#include <gtest/gtest.h>

#include <bitset>

void print_bits_t( uint32_t input ) {
    std::bitset<32> num( input );
    std::cout << num << std::endl;
}

TEST( NEXT_NUMBER, DEMO ) {
    print_bits_t( algorithm::next_number( 0b11011001111100 ) );
    ASSERT_EQ( 0b11011010001111, algorithm::next_number( 0b11011001111100 ) );
}