/**
 * @brief Three in One
 * Describe how you could use a single array to implement three stacks.
 *
 * @file three_one.h
 * @author Tushar Chugh
 */

#pragma once

#include <vector>
#include <assert.h>

namespace algorithm {
template<typename T> class MultiStack {
public:
    using value_type      = typename std::vector<T>::value_type;
    using size_type       = typename std::vector<T>::size_type;
    using reference       = typename std::vector<T>::reference;
    using const_reference = typename std::vector<T>::const_reference;

private:
    using iterator = typename std::vector<T>::iterator;

    size_type num_stacks_;
    std::vector<size_type> sizes_;
    std::vector<T> data_;
    std::vector<iterator> tops_;
    std::vector<iterator> begins_;

public:
    explicit MultiStack( size_type total_size, size_type num_stacks )
        : num_stacks_( num_stacks ), sizes_( num_stacks ), data_( total_size ){
        assert(total_size > num_stacks_);

        size_type size_each_container = total_size / num_stacks_;
        auto data_iter = data_.begin();

        for ( auto& size : sizes_ ) {
            size = size_each_container;
            std::advance(data_iter, size);
            tops_.push_back(data_iter);
        }
        begins_ = tops_;
    }

    explicit MultiStack( const std::vector<size_type>& sizes )
        : num_stacks_( sizes.size() ), sizes_( num_stacks_ ) {
        unsigned int total_size = 0;
        for(auto& size: sizes)
            total_size += size;
        data_.reserve(total_size);
        auto data_iter = data_.begin();
        for ( size_type i = 0; i < num_stacks_; ++i ) {
            sizes_[i] = sizes[i];
            std::advance(data_iter, sizes[i]);
            tops_.push_back(data_iter);
        }
        begins_ = tops_;
    }

    inline reference top( size_type stack_id ) {
        return *(tops_.at( stack_id ));
    }

    inline const_reference top( size_type stack_id ) const {
        return tops_.at( stack_id );
    }

    inline bool empty(size_type stack_id) const {
        return begins_.at(stack_id) == tops_.at(stack_id);
    }

    inline size_type size(size_type stack_id) const {
        return std::distance(begins_.at(stack_id), tops_.at(stack_id));
    }

    inline void push( size_type stack_id, const value_type& value ) {
        *(tops_.at(stack_id)) = value;
    }

    inline void push(size_type stack_id, value_type&& value ) {
        *(tops_.at(stack_id))++ = value;

    }

    inline void pop(size_type stack_id) {
        delete tops_.at(stack_id);
        --tops_.at(stack_id);
    }
};
} // namespace algorithm