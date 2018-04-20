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
template<class T> class Forward_List {
public:
    struct Forward_List_Node {
        const T& value_;
        std::shared_ptr<Forward_List_Node> next_ = nullptr;

        // constructor
        Forward_List_Node( const T& value ) : value_( value ) {}
    };
    using node_pointer = typename std::shared_ptr<Forward_List_Node>;

private:
    std::shared_ptr<Forward_List_Node> head_;
    size_t size_;

public:
    Forward_List() : head_( nullptr ), size_( 0 ) {}
    node_pointer push_front( const T& value ) {
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
};

} // namespace algorithm