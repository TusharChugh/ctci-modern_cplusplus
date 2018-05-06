/**
 * @brief Insertion
 * You are given two 32-bit numbers, Nand M, and two bit positions, i and j. Write a method to
 * insert Minto N such that M starts at bit j and ends at bit i. You can assume that the bits j
 * through i have enough space to fit all of M. That is, if M = 18811, you can assume that there are
 * at least 5 bits between j and i. You would not, for example, have j = 3 and i = 2, because M
 * could not fully fit between bit 3 and bit 2.
 *
 * EXAMPLE Input: N: 10000000000, M = 1011, i = 2, j = 6
 * Output: N = 10001001100
 *
 * @file insertion_bits.h
 * @author Tushar Chugh
 */

#pragma once

#include <cstdint>

namespace algorithm {
/**
 * @brief insert bits to the input at the given location
 *
 * @param input input number
 * @param bits bits to be inserted
 * @param start start loation of the input where bits are to be inserted
 * @param end end loation of the input where bits are to be inserted
 * @return uint32_t result after adding bits to input
 */
uint32_t insert_bits( uint32_t input, uint32_t bits, uint8_t start, uint8_t end ) {
    uint32_t mask = 0;
    // create a mask to clear the input bits from start to end
    // start with 1s (count of 1s equal num of required bits)
    // alternative for generating ones :
    // num = 1 << (end - start + 1)
    // num = num - 1
    for ( uint32_t num = 0; num <= end - start; ++num ) {
        mask += ( 1 << num );
    }

    // slide them to the required locations and then invert it
    mask = ~( mask << start );

    // apply the mask on the input and insert the bits
    return ( ( input & mask ) | ( bits << start ) );
}

/**
 * @brief insert bits to the input at the given location | alternative
 *
 * @param input input number
 * @param bits bits to be inserted
 * @param start start loation of the input where bits are to be inserted
 * @param end end loation of the input where bits are to be inserted
 * @return uint32_t result after adding bits to input
 */
uint32_t insert_bits_mask( uint32_t input, uint32_t bits, uint8_t start, uint8_t end ) {
    // create a mask to clear the input bits from start to end
    // start with 1s (count of 1s equal num of required bits)
    // slide them to the required locations and then invert it
    auto mask = ~( ( ( 1 << ( end - start + 1 ) ) - 1 ) << start );

    // apply the mask on the input and insert the bits
    return ( ( input & mask ) | ( bits << start ) );
}

} // namespace algorithm