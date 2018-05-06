#include "include/bit_manipulation/insertion_bits.h"
#include <gtest/gtest.h>

#include <bitset>

void print_bits( uint32_t input ) {
    std::bitset<32> num( input );
    std::cout << num << std::endl;
}

TEST( INSERTION_BITS, DEMO ) {
    uint32_t input = 0b10000000000;
    uint32_t bits  = 0b10011;

    uint32_t expected_output = 0b10001001100;
    auto output              = algorithm::insert_bits( input, bits, 2, 6 );
    ASSERT_EQ( expected_output, output );
}

TEST( INSERTION_BITS, DEMO_MASK ) {
    uint32_t input = 0b10000000000;
    uint32_t bits  = 0b10011;

    uint32_t expected_output = 0b10001001100;
    auto output              = algorithm::insert_bits_mask( input, bits, 2, 6 );
    ASSERT_EQ( expected_output, output );
}