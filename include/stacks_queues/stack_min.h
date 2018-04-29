/**
 * @brief Stack Min
 * How would you design a stack which, in addition to push and pop, has a function min which returns
 * the minimum element? Push, pop and min should all operate in 0(1) time
 *
 * @file stack_min.h
 * @author Tushar Chugh
 */

#pragma once

#include <stack>

namespace algorithm {
/**
 * @brief Stack which maintains the min value
 * Can be templated but in that case need to templatized the opertor as well
 */
class stack_min {
    using value_type      = typename std::stack<int>::value_type;
    using reference       = typename std::stack<int>::reference;
    using const_reference = typename std::stack<int>::const_reference;
    using size_type       = typename std::stack<int>::size_type;

private:
    std::stack<int> data_;
    std::stack<int> mins_;

public:
    stack_min()  = default;
    ~stack_min() = default;

    inline reference top() {
        return data_.top();
    }

    inline const_reference top() const {
        return data_.top();
    }

    inline bool empty() const noexcept {
        return data_.empty();
    }

    inline size_type size() const noexcept {
        return data_.size();
    }

    inline void push( const value_type& value ) {
        if ( mins_.empty() || value <= mins_.top() ) mins_.push( value );
        data_.push( value );
    }

    inline void push( value_type&& value ) {
        if ( mins_.empty() || value < mins_.top() ) mins_.push( std::move( value ) );
        data_.push( std::move( value ) );
    }

    inline void pop() {
        if ( data_.top() == mins_.top() ) mins_.pop();
        data_.pop();
    }

    inline reference min() noexcept {
        return mins_.top();
    }

    inline const_reference min() const {
        return mins_.top();
    }
};
} // namespace algorithm