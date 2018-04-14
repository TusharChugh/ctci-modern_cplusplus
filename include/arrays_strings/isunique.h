/**
 * @brief Is Unique
 * Implement an algorithm to determine if a string has all unique characters
 *
 * @file IsUnique.h
 * @author Tushar Chugh
 */

#include <iostream>
#include <string>
#include <vector>

constexpr uint8_t NUM_CHAR = 128;

/**
 * @brief detemine if a string has all unique characters
 * Assumes that the character set is ASCII
 * @param input input string
 * @return true if unique
 * @return false if not unique
 */
bool isUnique_hash( const std::string input ) {
    if ( input.length() > 128 ) return false;

    // Note: vector<bool> takes less than 8 bytes to store a value
    std::vector<bool> seen_chars( NUM_CHAR );
    for ( auto letter : input ) {
        if ( seen_chars.at( letter ) ) return false;
        seen_chars.at( letter ) = true;
    }
    return true;
}

/**
 * Notes:
 * 1. Running time is O(n)
 * 2. Input is constant as we are not modifying it
 * 3. Prefer .at() function for string as opposed to [] operatir
 * because .at checks whether pos is the valid position of a character in the string
 * 4. vector<bool> will try to pack the input as bits rather than bytes
 * 5. Use for_each loop with auto makes the code more robuts and clear
 *
 */