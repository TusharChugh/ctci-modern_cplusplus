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

#include <string>

namespace algorithm {

/**
 * @brief Given a string, count the length of the of string which it can be compressed to
 *
 * @param input input string
 * @return size_t length of the compressed string
 */
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

/**
 * @brief compress the string using the count of repeated characters
 * Notes:
 * 1. Run time complexity: O(N)
 * 2. Memory complexity: O(N)
 * 3. Use of iterators here is a bit ugly
 * @param input
 * @return std::string
 */
std::string compress( const std::string& input ) {
    size_t compressed_size = count_compressed( input );
    if ( compressed_size >= input.length() ) return input;
    std::string compressed_str( compressed_size, ' ' );

    size_t consecutive_count = 0;
    auto compressed_str_iter = compressed_str.begin();
    for ( auto iter = input.begin(); iter != input.end(); ++iter ) {
        ++consecutive_count;
        if ( ( iter + 1 ) == input.end() || ( *iter != *( iter + 1 ) ) ) {
            *compressed_str_iter = *iter;
            ++compressed_str_iter;
            auto count_str = std::to_string( consecutive_count );
            std::copy( count_str.begin(), count_str.end(), compressed_str_iter );
            compressed_str_iter += count_str.length();
            consecutive_count = 0;
        }
    }

    return compressed_str;
}
} // namespace algorithm