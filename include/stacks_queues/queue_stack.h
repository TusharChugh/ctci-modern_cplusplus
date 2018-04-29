/**
 * @brief Queue via Stacks
 * Implement a MyQueue class which implements a queue using two stacks.
 *
 * @file queue_stack.h
 * @author Tushar Chugh
 */

#pragma once

#include <stack>

namespace algorithm {
/**
 * @brief queue implemented using stacks
 * Can templetize the container used with the stack but keeping things simple here. Default
 * container used is std::deque
 * Operators, swap and other useful functions not implemented
 * @tparam
 */
template<typename T> class queue_stack {
public:
    using value_type      = typename std::stack<T>::value_type;
    using size_type       = typename std::stack<T>::size_type;
    using reference       = typename std::stack<T>::reference;
    using const_reference = typename std::stack<T>::const_reference;

private:
    std::stack<T> input_stack;
    std::stack<T> output_stack;

    void input_output_transfer() {
        while ( !input_stack.empty() ) {
            output_stack.push( input_stack.top() );
            input_stack.pop();
        }
    }

public:
    queue_stack()  = default;
    ~queue_stack() = default;

    inline reference front() {
        if ( output_stack.empty() ) input_output_transfer();
        return output_stack.top();
    }

    inline const_reference front() const {
        if ( output_stack.empty() ) input_output_transfer();
        return output_stack.top();
    }

    inline bool empty() const {
        return ( input_stack.empty() && output_stack.empty() );
    }

    inline size_type size() const {
        return ( input_stack.size() + output_stack.size() );
    }

    inline void push( const value_type& value ) {
        input_stack.push( value );
    }

    inline void push( value_type&& value ) {
        input_stack.push( std::move( value ) );
    }

    inline void pop() {
        if ( output_stack.empty() ) input_output_transfer();
        return output_stack.pop();
    }
};
} // namespace algorithm
