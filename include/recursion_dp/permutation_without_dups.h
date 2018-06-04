/**
 * @brief Permutations without Dups
 * Write a method to compute all permutations of a string of unique characters.
 *
 * @file permutation_without_dups.h
 * @author Tushar Chugh
 */

#pragma once

#include <string>
#include <vector>

namespace algorithm {
std::string append_at_pos( const std::string& input, char letter, size_t pos ) {
    return input.substr( 0, pos ) + letter + input.substr( pos, input.length() - pos );
}

std::vector<std::string> perms_no_dups( std::string input ) {
    std::vector<std::string> result;
    if ( input.empty() ) {
        result.push_back( "" );
        return result;
    }
    auto front_letter = input.front();
    auto words        = perms_no_dups(
        input.substr( 1, input.length() - 1 ) ); // duplicates of input - first letter
    for ( auto word : words ) {
        for ( size_t pos = 0; pos <= word.length(); ++pos ) {
            result.push_back( append_at_pos( word, front_letter, pos ) );
        }
    }
    return result;
}

std::vector<std::string> perms_no_dups_bootomsup( std::string input ) {
    std::vector<std::string> result;
    if ( input.empty() ) {
        result.push_back( "" );
        return result;
    }

    for ( size_t pos = 0; pos < input.length(); ++pos ) {
        auto before = input.substr( 0, pos );
        auto after  = input.substr( pos + 1, input.length() - pos - 1 );
        auto words  = perms_no_dups_bootomsup( before + after );
        for ( auto word : words )
            result.push_back( input.at( pos ) + word );
    }
    return result;
}

} // namespace algorithm