/**
 * @brief Three in One
 * Describe how you could use a single array to implement three stacks.
 *
 * @file three_one.h
 * @author Tushar Chugh
 */

#pragma once

#include <assert.h>
#include <vector>

namespace algorithm {
template<typename T> class MultiStack {
public:
    using value_type      = typename std::vector<T>::value_type;
    using size_type       = typename std::vector<T>::size_type;
    using reference       = typename std::vector<T>::reference;
    using const_reference = typename std::vector<T>::const_reference;

private:
    using iterator = typename std::vector<T>::iterator;

    const size_type num_stacks_;
    std::vector<size_type> stack_capacities_;
    std::vector<size_type> sizes_;
    std::vector<T> data_;

    size_type index_of_top( size_type stack_id ) const {
        size_type offset = stack_id * stack_capacities_[stack_id];
        size_type size   = sizes_.at( stack_id );
        return offset + size - 1;
    }

    bool is_full( size_type stack_id ) const {
        return sizes_.at( stack_id ) == stack_capacities_.at( stack_id );
    }

public:
    explicit MultiStack( size_type num_stacks, size_type stack_capacity )
        : num_stacks_( num_stacks ), stack_capacities_( num_stacks, stack_capacity ),
          sizes_( num_stacks ), data_( num_stacks * stack_capacity ) {}

    explicit MultiStack( const std::vector<size_type>& stack_capacities )
        : num_stacks_( stack_capacities.size() ), stack_capacities_( stack_capacities ),
          sizes_( num_stacks_ ) {
        unsigned int total_capacity = 0;
        for ( auto& stack_capacity : stack_capacities )
            total_capacity += stack_capacity;
        data_.reserve( total_capacity );
    }

    inline reference top( size_type stack_id ) {
        if ( empty( stack_id ) ) std::__throw_underflow_error( "Stack is empty" );
        return data_.at( index_of_top( stack_id ) );
    }

    inline const_reference top( size_type stack_id ) const {
        if ( empty( stack_id ) ) std::__throw_underflow_error( "Stack is empty" );
        return data_.at( index_of_top( stack_id ) );
    }

    inline bool empty( size_type stack_id ) const {
        return sizes_.at( stack_id ) == 0;
    }

    inline size_type size( size_type stack_id ) const {
        return sizes_.at( stack_id );
    }

    inline void push( size_type stack_id, const value_type& value ) {
        if ( is_full( stack_id ) ) std::__throw_out_of_range( "Stack is full" );
        ++sizes_.at( stack_id );
        data_.at( index_of_top( stack_id ) ) = value;
    }

    inline void push( size_type stack_id, value_type&& value ) {
        if ( is_full( stack_id ) ) std::__throw_out_of_range( "Stack is full" );
        ++sizes_.at( stack_id );
        data_.at( index_of_top( stack_id ) ) = std::move( value );
    }

    inline void pop( size_type stack_id ) {
        if ( empty( stack_id ) ) std::__throw_underflow_error( "Stack is empty" );
        data_.erase( static_cast<iterator>( index_of_top( stack_id ) ) );
        --sizes_.at( stack_id );
    }
};
} // namespace algorithm