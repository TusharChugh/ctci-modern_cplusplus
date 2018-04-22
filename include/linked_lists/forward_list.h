/**
 * @brief
 *
 * @file forward_list.h
 * @author Tushar Chugh
 */
// TODO's add support for rvalue references
#pragma once

#include <memory>

namespace algorithm {

template<class T> struct Forward_List_Node {
    T& value_;
    std::shared_ptr<Forward_List_Node> next_ = nullptr;

    // constructor
    Forward_List_Node( T& value ) : value_( value ) {}
    // Destructor
    ~Forward_List_Node() = default;
};

template<class T> class Forward_List {
public:
    using node_pointer = typename std::shared_ptr<Forward_List_Node<T>>;

private:
    std::shared_ptr<Forward_List_Node<T>> head_;
    size_t size_;

public:
    Forward_List() : head_( nullptr ), size_( 0 ) {}
    node_pointer push_front( T& value ) {
        auto node   = std::make_shared<Forward_List_Node<T>>( value );
        node->next_ = head_;
        head_       = node;
        ++size_;

        return head_;
    }

    inline size_t size() {
        return size_;
    }

    node_pointer front() {
        return head_;
    }
};

} // namespace algorithm