/**
 * @brief Partition:
 * Write code to partition a linked list around a value x, such that all nodes less than x come
 * before all nodes greater than or equal to x. If x is contained within the list, the values of x
 * only need to be after the elements less than x (see below). The partition element x can appear
 * anywhere in the "right partition"; it does not need to appear between the left and right
 * partitions.
 *
 * EXAMPLE
 * Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
 * Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
 *
 * @file partition.h
 * @author Tushar Chugh
 */

#pragma once

#include "forward_list.h"

namespace algorithm {

template<typename T>
std::shared_ptr<Forward_List_Node<T>> partition_stable( std::shared_ptr<Forward_List_Node<T>> node,
                                                        const T& key ) {
    using node_pointer       = std::shared_ptr<Forward_List_Node<T>>;
    node_pointer before_head = nullptr;
    node_pointer before_end  = nullptr;
    node_pointer after_head  = nullptr;
    node_pointer after_end   = nullptr;

    while ( node != nullptr ) {
        auto next   = node->next_;
        node->next_ = nullptr;
        if ( node->value_ < key ) {
            if ( before_head == nullptr ) {
                before_head = node;
                before_end  = node;
            } else {
                before_end->next_ = node;
                before_end        = node;
            }
        } else {
            if ( after_end == nullptr ) {
                after_head = node;
                after_end  = node;
            } else {
                after_end->next_ = node;
                after_end        = node;
            }
        }
        node = next;
    }

    if ( before_end == nullptr ) return after_head;
    before_end->next_ = after_head;
    return before_head;
}
} // namespace algorithm