/**
 * @brief Flip Bit to Win
 * You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to find the
 * length of the longest sequence of 1s you could create.
 * EXAMPLE Input: 1775 (or 11011101111)
 * Output: 8
 *
 * @file flip_bit_win.h
 * @author Tushar Chugh
 */

#pragma once

#include <limits.h>
#include <algorithm>
#include <cstddef>

namespace algorithm {

/**
 * @brief
 * Notes:
 * 1. >>> operator is not available in C++
 * 2. >> operator preserves the sign bit
 * 3. Cast to unsigned int if we need to do logical right shift as in Java
 * @param input
 * @return std::size_t
 */
std::size_t flip_bit_win( int input ) {
    // all ones, equivalent to ~input == 1
    if ( input == -1 ) return sizeof( int ) * 8;

    std::size_t max_length      = 1;
    std::size_t current_length  = 0;
    std::size_t previous_length = 0;

    while ( input != 0 ) {
        if ( input & 1 == 1 )
            ++current_length;
        else {
            previous_length = ( input & 0b10 ) == 0 ? 0 : current_length;
            current_length  = 0;
        }
        max_length = std::max( previous_length + 1 + current_length, max_length );
        input      = static_cast<unsigned int>( input ) >> 1;
    }
    return max_length;
}

} // namespace algorithm