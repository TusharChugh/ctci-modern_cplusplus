/**
 * @brief Check Permutation: Given two strings, write a method to decide if one is a  permutation of
 * the other.
 *
 * @file check_permutation.h
 * @author Tushar Chugh
 */

#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>

namespace algorithm {

constexpr size_t NUM_CHAR = 256;

// Let length of input be N and length of other be M

/**
 * @brief check if the two strings are permutation of each other
 * Notes:
 * 1. Running time O(N log(N) + M log(M)), Memory complexity O(1)
 * 2. Didn't have constant input params as we modify the strings while sorting them
 * 3. input params are pass by value as we modify the strings. Pass by reference will
 * violate the principle of least astonishment as well as won't work for rvalue references
 *
 * @param input input string 1
 * @param other input string 2
 * @return true true if one is the permutation of the other
 * @return false false if one is not the permutation of the other
 */
bool check_permutation_sort( std::string input, std::string other ) noexcept {
    // return false if both the strings are of different length
    if ( input.length() != other.length() ) return false;

    // sort both the strings
    std::sort( input.begin(), input.end() );
    std::sort( other.begin(), other.end() );

    return ( input.compare( other ) == 0 );
}

/**
 * @brief check if the two strings are permutation of each other
 * Notes:
 * 1. Running time O(N + M), Memory complexity O(1)
 * 2. Input params are constant references and can accept rvalues
 * 3. std::unordered_map is implemented using hash maps (const time lookup)
 * @param input input string 1
 * @param other input string 2
 * @return true true if one is the permutation of the other
 * @return false false if one is not the permutation of the other
 */
bool check_permutation_map( const std::string& input, const std::string& other ) noexcept {
    // return false if both the strings are of different length
    if ( input.length() != other.length() ) return false;

    std::unordered_map<char, size_t> input_counts;
    std::unordered_map<char, size_t> other_counts;

    // Create a dictionary of chars and count for inputs
    for ( auto in : input ) {
        if ( input_counts.count( in ) )
            ++input_counts.at( in );
        else
            input_counts.insert( std::make_pair( in, 1 ) );
    }

    for ( auto ot : other ) {
        if ( other_counts.count( ot ) )
            ++other_counts.at( ot );
        else
            other_counts.insert( std::make_pair( ot, 1 ) );
    }

    // Check if both the maps are equal
    return ( input_counts == other_counts );
}

/**
 * @brief check if the two strings are permutation of each other
 * Notes:
 * 1. Running time O(N + M), Memory complexity O(1)
 * 2. Input params are constant references and can accept rvalues
 * 3. Using arrays is less expensive as maps
 * 4. Using std::array as compared to c-style array make code cleaner and more robust
 * @param input input string 1
 * @param other input string 2
 * @return true true if one is the permutation of the other
 * @return false false if one is not the permutation of the other
 */
bool check_permutation_arraycount( const std::string& input, const std::string& other ) noexcept {
    // return false if both the strings are of different length
    if ( input.length() != other.length() ) return false;

    std::array<size_t, NUM_CHAR> input_counts{};
    std::array<size_t, NUM_CHAR> other_counts{};

    // Create a dictionary of chars and count for inputs
    for ( auto in : input )
        input_counts.at( in )++;

    for ( auto ot : other )
        other_counts.at( ot )++;

    // Check if both the maps are equal
    return ( input_counts == other_counts );
}
} // namespace algorithm