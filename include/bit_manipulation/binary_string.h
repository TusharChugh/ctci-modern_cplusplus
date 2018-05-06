/**
 * @brief Binary to String
 * Given a real number between 8 and 1 (e.g., 0.72) that is passed in as a
 * double, print the binary representation. If the number cannot be represented accurately in binary
 * with at most 32 characters, print "ERROR:'
 *
 * @file binary_string.h
 * @author Tushar Chugh
 */

#pragma once

#include <sstream>
#include <string>

namespace algorithm {
/**
 * @brief Converts double to a binary string representation
 * Running time O(b) : number of bits
 * Notes:
 * 1. << operator doesn't work for double
 * 2. Getting size of the stream take O(N) time (refer seekg, tellg), we done't want to calculate it
 * after every iterator so we keep track of it manually in the code
 * @param input input number
 * @return std::string binary converted string
 */
std::string binary_string( double input ) {
    if ( input >= 1 || input <= 0 ) return "ERROR";

    std::stringstream result;
    std::size_t result_size = 0;

    while ( input > 0 ) {
        if ( result_size == 32 ) return "ERROR";

        input = input * 2;
        if ( input >= 1 ) {
            result << '1';
            input -= 1;
        } else {
            result << '0';
        }

        ++result_size;
    }

    return result.str();
}
} // namespace algorithm