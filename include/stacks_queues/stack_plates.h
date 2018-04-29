/**
 * @brief Stack of Plates
 *  Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in
 * real life, we would likely start a  new stack when the previous stack exceeds some threshold.
 * Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of
 * several stacks and should create a new stack once the previous one exceeds capacity. SetOfStacks.
 * push () and SetOfStacks. pop() should behave identically to a  single stack (that is, pop ( )
 * should return the same values as it would if there were just a single stack).
 *
 *
 * @file stack_plates.h
 * @author Tushar Chugh
 */

#pragma once

#include <stack>

namespace algorithm {

/**
 * @brief Set of stacks
 * Can add the container type for the stack as the template parameter. Keeping it simple here
 * @tparam T type of stack elements
 */
template<typename T> class set_stacks {
public:
    using stack_type      = std::stack<T>;
    using value_type      = typename stack_type::value_type;
    using size_type       = typename stack_type::size_type;
    using reference       = typename stack_type::reference;
    using const_reference = typename stack_type::const_reference;

private:
    std::stack<std::stack<T>> stacks;
    const size_type stack_capacity_;
    size_type num_stacks_used;

public:
    set_stacks( size_type stack_capacity )
        : stack_capacity_( stack_capacity ), num_stacks_used( 0 ) {
        if ( stack_capacity == 0 )
            std::__throw_invalid_argument( "Capacity needs to be greater than 1" );
    }

    ~set_stacks() = default;

    inline reference top() {
        return stacks.top().top();
    }

    inline const_reference top() const {
        return stacks.top().top();
    }

    inline bool empty() const {
        return stacks.empty();
    }

    inline size_type size() const {
        return ( num_stacks_used - 1 ) * stack_capacity_ + stacks.top().size();
    }

    inline void push( const value_type& value ) {
        if ( stacks.empty() || stacks.top().size() == stack_capacity_ ) {
            stacks.push( std::stack<T>{} );
            ++num_stacks_used;
        }
        stacks.top().push( value );
    }

    inline void push( value_type&& value ) {
        if ( stacks.empty() || stacks.top().size() == stack_capacity_ ) {
            stacks.push( std::stack<T>{} );
            ++num_stacks_used;
        }
        stacks.top().push( std::move( value ) );
    }

    inline void pop() {
        stacks.top().pop();
        if ( stacks.top().empty() ) {
            stacks.pop();
            --num_stacks_used;
        }
    }
};
} // namespace algorithm