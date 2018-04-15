/**
 * @brief Is Unique
 * Implement an algorithm to determine if a string has all unique characters
 *
 * @file IsUnique.h
 * @author Tushar Chugh
 */

#pragma once

#include <string>
#include <vector>

namespace algorithm {

constexpr size_t NUM_CHAR = 256;

/**
 * @brief detemine if a string has all unique characters
 * Assumes that the character set is ASCII
 * @param input input string
 * @return true if unique
 * @return false if not unique
 */
bool isUnique_hash( const std::string& input ) {
    if ( input.length() > NUM_CHAR ) return false;

    // Note: vector<bool> doesn't take a byte to store a value
    std::vector<bool> seen_chars( NUM_CHAR );
    for ( auto letter : input ) {
        if ( seen_chars.at( letter ) ) return false;
        seen_chars.at( letter ) = true;
    }
    return true;
}

/**
 * Notes:
 * 1. Run time complexity is O(n)
 * 2. Memory complexity is O(1) (approx 128/8 bytes)
 * 3. Input is constant as we are not modifying it
 * 4. Prefer .at() function for string as opposed to [] operatir
 * because .at checks whether pos is the valid position of a character in the string
 * 5. vector<bool> will try to pack the input as bits rather than bytes
 * 6. Use for_each loop with auto makes the code more robuts and clear
 *
 */

} // namespace algorithm