/**
 * @brief Group Anagrams: Write a method to sort an array of strings so that all the anagrams are
 * next to each other.
 *
 * @file group_anagrams.h
 * @author Tushar Chugh
 */

#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

namespace algorithm {
void group_anagrams( std::vector<std::string>& input ) {
    std::unordered_multimap<std::string, std::string> sorted_input_map;

    for ( const auto& word : input ) {
        std::string sorted_word = word;
        std::sort( sorted_word.begin(), sorted_word.end() );
        sorted_input_map.emplace( sorted_word, word );
    }

    size_t index = 0;

    for ( const auto& bucket : sorted_input_map ) {
        input.at( index++ ) = bucket.second;
    }
}
} // namespace algorithm