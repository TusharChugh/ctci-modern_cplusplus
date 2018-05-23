/**
 * @brief Magic Index
 * A magic index in an array A [e ... n -1] is defined to be an index such that A[ i] = i. Given a
 * sorted array of distinct integers, write a method to find a magic index, if one exists, in array
 * A. FOLLOW UP What if the values are not distinct?
 *
 * @file magic_index.h
 * @author Tushar Chugh
 */

#pragma once

#include <vector>

namespace algorithm {

int magic_index_helper( const std::vector<int>& input, int begin, int end );

int magic_index( const std::vector<int>& input ) {
    int begin = 0;
    int end   = input.size() - 1;
    return magic_index_helper( input, begin, end );
}

int magic_index_helper( const std::vector<int>& input, int begin, int end ) {
    if ( begin > end ) return 0;

    auto mid = ( begin + end ) / 2;

    if ( input.at( mid ) == mid )
        return mid;
    else if ( input.at( mid ) < mid )
        return magic_index_helper( input, mid + 1, end );
    else
        return magic_index_helper( input, begin, mid - 1 );
}

} // namespace algorithm