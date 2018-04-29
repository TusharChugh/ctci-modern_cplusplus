/**
 * @brief Sort Stack
 * Write a program to sort a stack such that the smallest items are on the top. You can use an
 * additional temporary stack, but you may not copy the elements into any other data structure (such
 * as an array). The stack supports the following operations: push, pop, top, and isEmpty.
 *
 * @file sort_stack.h
 * @author Tushar Chugh
 */

#pragma once
#include <functional>
#include <stack>

namespace algorithm {
template<typename T, typename Compare = std::less<T>>
std::stack<T> sort_stack( std::stack<T> input, Compare comp = Compare() ) {
    std::stack<T> sorted;
    while ( !input.empty() ) {
        // Step 1: store the top of input stack in temporary variable
        const auto poped_element = input.top();
        input.pop();

        // Step2: move the elements of sorted to input less than the temp variable
        while ( !sorted.empty() && comp( sorted.top(), poped_element ) ) {
            input.push( sorted.top() );
            sorted.pop();
        }

        // Step 3: insert the temporary values to sorted stack
        sorted.push( poped_element );

        // Step 4: move the elements back from input to sorted
        while ( !input.empty() && comp( input.top(), sorted.top() ) ) {
            sorted.push( input.top() );
            input.pop();
        }
    }
    return sorted;
}
} // namespace algorithm