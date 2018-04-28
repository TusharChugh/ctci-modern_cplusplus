/**
 * @brief Three in One
 * Describe how you could use a single array to implement three stacks.
 *
 * @file three_one.h
 * @author Tushar Chugh
 */

#pragma once

#include <vector>

namespace algorithm {
template<typename T> class MultiStack {
public:
    using value_type      = typename std::vector::value_type;
    using size_type       = typename std::vector::size_type;
    using reference       = typename std::vector::reference;
    using const_reference = typename std::vector::const_reference;

private:
    using iterator = typename std::vector::reference;

    size_t num_stacks_;
    const std::vector<size_t> sizes_;
    std::vector<T> data;
    std::vector<iterator> tops;

public:
    explicit MultiStack( size_t total_size, size_t num_stacks )
        : num_stacks_( num_stacks ), sizes_( num_stacks ), data( total_size ), tops( num_stacks ) {
        size_t size_each_container = total_size / num_stacks_;
        for ( auto& size : sizes_ ) {
            size = size_each_container;
        }
    }

    explicit MultiStack( const std::vector& sizes )
        : num_stacks_( sizes.size() ), sizes_( num_stacks_ ) {
        for ( size_t i = 0; i < num_stacks_; ++i ) {
            sizes_[i] = sizes[i];
        }
    }

    inline reference top( size_t stack_id ) {
        return tops.at( stack_id );
    }

    inline const_reference top( size_t stack_id ) const {
        return tops.at( stack_id );
    }

    inline bool empty() const {
        return container.empty();
    }

    inline size_type size() const {
        return container.size();
    }

    inline void push( const value_type& value ) {
        return container.push_back( value );
    }

    inline void push( value_type&& value ) {
        return container.push_back( std::move( value ) );
    }

    inline void pop() {
        return container.pop_back();
    }

    void swap( stack& other ) noexcept {
        using std::swap;
        swap( container, other.container );
    }
};
} // namespace algorithm