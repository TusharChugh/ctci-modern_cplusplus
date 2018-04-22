/**
 * @brief Delete Middle Node
 * Implement an algorithm to delete a node in the middle (i.e., any node but
 * the first and last node, not necessarily the exact middle) of a singly linked list, given only
 * access to that node. EXAMPLE: Input: the node c from the linked list a -> b -> c -> d -> e -> f
 * Result: nothing is returned, but the new linked list looks like a -> b -> d -> e -> f
 *
 * @file remove_node.h
 * @author Tushar Chugh
 */

#pragma once

#include "forward_list.h"

namespace algorithm {
template<typename T> void remove_node( std::shared_ptr<Forward_List_Node<T>> input_node ) {
    if ( input_node == nullptr ) return;
    if ( input_node->next_ == nullptr ) return;

    input_node->value_ = ( input_node->next_ )->value_;
    input_node->next_  = ( input_node->next_ )->next_;
}
} // namespace algorithm