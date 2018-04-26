/**
 * @brief Palindrome
 * A function to check if a linked list is a palindrome
 *
 * @file palindrome_list.h
 * @author Tushar Chugh
 */

#pragma once

#include <forward_list>
#include <stack>

namespace algorithm {

template<typename T> bool is_palindrome_reverse( const std::forward_list<T>& input ) {
    std::forward_list<T> reversed_input( input );
    reversed_input.reverse();
    return reversed_input == input;
}

template<typename T> bool is_palindrome_stack( const std::forward_list<T>& input ) {
    std::stack<T> half_input;
    auto fast_iter = input.begin();
    auto iter      = input.begin();

    while ( fast_iter != input.end() && ++fast_iter != input.end() ) {
        half_input.push( *iter );
        ++iter;
        ++fast_iter;
    }

    if ( std::distance( input.begin(), input.end() ) % 2 ) ++iter;

    while ( iter != input.end() ) {
        if ( *iter != half_input.top() ) return false;
        half_input.pop();
        ++iter;
    }
    return true;
}

} // namespace algorithm