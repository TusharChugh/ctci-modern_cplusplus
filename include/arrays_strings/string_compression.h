/**
 * @brief String Compression
 * Implement a  method to perform basic string compression using the counts of repeated characters.
 * For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not
 * become smaller than the original string, your method should return the original string. You can
 * assume the string has only uppercase and lowercase letters (a - z).
 *
 * @file string_compression.h
 * @author Tushar Chugh
 */

#pragma once

#include <iostream>
#include <string>

namespace algorithm {
// size_t num_digits( size_t num ) {
//     size_t digits = 1;
//     while ( num / 10 )
//         ++digits;
//     return digits;
// }

size_t count_compressed( const std::string& input ) {
    size_t compressed_size   = 0;
    size_t consecutive_count = 0;

    for ( auto iter = input.begin(); iter != input.end(); ++iter ) {
        ++consecutive_count;
        if ( ( iter + 1 ) == input.end() || ( *iter != *( iter + 1 ) ) ) {
            compressed_size += std::to_string( consecutive_count ).length() + 1;
            consecutive_count = 0;
        }
    }
    return compressed_size;
}

std::string compress( const std::string& input ) {
    size_t compressed_size = count_compressed( input );
    std::cout << compressed_size;
    if ( compressed_size >= input.length() ) return input;
    std::string compressed_str( compressed_size, ' ' );

    size_t consecutive_count = 0;
    auto compressed_str_iter = compressed_str.begin();
    for ( auto iter = input.begin(); iter != input.end(); ++iter ) {
        ++consecutive_count;
        if ( ( iter + 1 ) == input.end() || ( *iter != *( iter + 1 ) ) ) {
            *compressed_str_iter = *iter;
            ++compressed_str_iter;

            *compressed_str_iter = std::to_string( consecutive_count );
            ++compressed_str_iter;
        }
    }

    return compressed_str;
}
} // namespace algorithm