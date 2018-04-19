/**
 * @brief
 *
 * @file forward_list.h
 * @author your name
 * @date 2018-04-18
 */

#pragma once

#include <memory>

// ToDo: take in constant reference

namespace algorithm {
template<class T> class Forward_List {
public:
    struct Forward_List_Node {
        T& value_;
        std::shared_ptr<Forward_List_Node> next_ = nullptr;

        // constructor
        Forward_List_Node( T& value ) : value_( value ) {}
    };
    using node_pointer = typename std::shared_ptr<Forward_List_Node>;

private:
    std::shared_ptr<Forward_List_Node> head_;
    // std::unique_ptr<node> tail_;
    size_t size_;

public:
    Forward_List() : head_( nullptr ), size_( 0 ) {}
    node_pointer push_front( T& value ) {
        auto node   = std::make_shared<Forward_List_Node>( value );
        node->next_ = head_;
        head_       = node;
        ++size_;

        return head_;
    }

    inline size_t size() {
        return size_;
    }

    node_pointer begin() {
        return head_;
    }
    // Forward_List_Node end();
};

} // namespace algorithm