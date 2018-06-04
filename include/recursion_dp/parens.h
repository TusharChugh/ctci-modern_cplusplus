/**
 * @brief Parens
 * Implement an algorithm to print all valid (i.e., properly opened and closed) combinations of n
 * pairs of parentheses.
 * EXAMPLE Input: 3
 * Output: ((())) , (()()), ()(()), (())(), ()()()
 *
 * @file parens.h
 * @author Tushar Chugh
 */

#pragma once

#include <string>
#include <unordered_set>
#include <vector>

#include <iostream>

namespace algorithm {

void add_paren( std::vector<std::string>& list, int left_rem, int right_rem, std::string str,
                int index ) {
    if ( left_rem < 0 || right_rem < left_rem ) return;
    if ( left_rem == 0 && right_rem == 0 )
        list.push_back( str );
    else {
        str.at( index ) = '(';
        add_paren( list, left_rem - 1, right_rem, str, index + 1 );

        str.at( index ) = ')';
        add_paren( list, left_rem, right_rem - 1, str, index + 1 );
    }
}

/**
 * @brief same as the book
 *
 * @param count
 * @return std::vector<std::string>
 */
std::vector<std::string> generate_parens( int count ) {
    std::string str( count * 2, ' ' );
    std::vector<std::string> list;
    add_paren( list, count, count, str, 0 );
    return list;
}
} // namespace algorithm