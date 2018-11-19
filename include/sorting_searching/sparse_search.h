/**
 * @brief Sparse Search: Given a sorted array of strings that is interspersed with empty strings,
 * write a method to find the location of a given string.
 * EXAMPLE
 * Input: ball, {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""}
 * Output: 4
 *
 * @file sparse_search.h
 * @author your name
 * @date 2018-06-28
 */

#pragma once

#include <string>
#include <vector>

namespace algorithm {
int get_nearest_nonempty_leftindex( const std::vector<std::string>& input, int index, int first,
                                    int last ) {
    if ( !input.at( index ).empty() ) return index;
    int left  = index - 1;
    int right = index + 1;

    while ( true ) {
        if ( left < first && right > last ) return -1;
        if ( right <= last && !input[right].empty() ) return right;
        if ( left >= first && !input[left].empty() ) return left;

        ++right;
        --left;
    }
}

int binary_search( const std::vector<std::string>& input, const std::string& query, int first,
                   int last ) {
    if ( first > last ) return -1;
    int mid = ( first + last ) / 2;

    mid = get_nearest_nonempty_leftindex( input, mid, first, last );

    if ( mid < 0 ) return mid;

    if ( query == input.at( mid ) )
        return mid;
    if ( query < input.at( mid ) )
        return binary_search( input, query, first, mid - 1 );
    else
        return binary_search( input, query, mid + 1, last );
}

int sparse_search( const std::vector<std::string>& input, const std::string& query ) {
    if ( input.empty() ) return -1;
    return  binary_search( input, query, 0, input.size() - 1 );
}
} // namespace algorithm