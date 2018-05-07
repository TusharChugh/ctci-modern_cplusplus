/**
 * @brief Next Number
 * Given a positive integer, print the next smallest and the next largest number that have the same
 * number of 1 bits in their binary representation.
 *
 * @file next_number.h
 * @author Tushar Chugh
 */

#pragma once

namespace algorithm {
/**
 * @brief Flips the bits to generate a number bigger than the input keeping number of one bits as
 * same
 * returns 0 if the greater number requires more bits than the input
 * @param input give number
 * @return unsigned int number with flipped bits
 */
unsigned int next_number( unsigned int input ) {
    auto input_copy          = input;
    unsigned int count_zeros = 0;
    unsigned int count_ones  = 0;

    while ( ( input_copy != 0 ) && ( ( input_copy & 1 ) == 0 ) ) {
        ++count_zeros;
        input_copy >>= 1;
    }

    while ( ( input_copy & 1 ) == 1 ) {
        ++count_ones;
        input_copy >>= 1;
    }

    if ( count_zeros + count_ones == sizeof( input ) * 8 || count_zeros + count_ones == 0 )
        return 0;

    auto zero_flip_pos = count_zeros + count_ones;

    input |= ( 1 << zero_flip_pos );          // Flip rightmost non-training zeros
    input &= ~( ( 1 << zero_flip_pos ) - 1 ); // Clear all bits to the right of zero flip position
    input |= ( 1 << ( count_ones - 1 ) ) - 1; // Insert ones to the right

    return input;
}
} // namespace algorithm