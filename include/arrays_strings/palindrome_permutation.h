/**
 * @brief Palindrome Permutation
 *  Check if a string is a permutation of a palindrome.
 *  A palindrome is a word or phrase that is the same forwards and backwards.
 *  A permutation is a rearrangement of letters. The palindrome does not need to be limited to just
 *  dictionary words.
 *
 *  EXAMPLE Input: TactoCoa Output: True (permutations: "tacoocat". "atcoocta". etc.)
 *
 * @file palindrome_permutation.h
 * @author Tushar Chugh
 */

#pragma once

#include <array>
#include <string>

constexpr size_t NUM_ALPHABETS = 26;

/**
 * @brief helper function to convert char to a number in range from 0 to 25
 *
 * @param input character
 * @return int interger from 0
 */
uint8_t char_to_number( const char input ) {
    if ( ( input - 'a' >= 0 ) && ( input - 'z' <= 0 ) ) {
        return input - 'a';
    }
    std::__throw_invalid_argument( "Not a lower case alphabet" );
}

/**
 * @brief Check if a string is a permutation of a palindrome
 * 1. Run time complexity
 * 2. Memory complexity
 * 3. Case insensitive
 * @param input input string
 * @return true if the string is a permutation of palindrome
 * @return false  if the string is not a permutation of palindrome
 */
bool is_palindrom_permutation( const std::string& input ) {
    // Build frequency table for the the charachters
    std::array<size_t, NUM_ALPHABETS> frequencies{};

    for ( auto letter : input )
        ++frequencies.at( char_to_number( letter ) );

    // Check if no more than one character has odd frequency
    bool seen_one_frequency = false;
    for ( auto frequency : frequencies ) {
        if ( frequency % 2 ) {
            if ( seen_one_frequency ) return false;
            seen_one_frequency = true;
        }
    }
    return true;
}