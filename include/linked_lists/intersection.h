/**
 * @brief Intersection
 * Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting
 * node. Note that the intersection is defined based on reference, not value. That is, if the kth
 * node of the first linked list is the exact same node (by reference) as the jth node of the second
 * linked list, then they are intersecting.
 *
 * @file intersection.h
 * @author Tushar Chugh
 */

#pragma once

#include <unordered_set>
#include "forward_list.h"

namespace algorithm {
template <typename T>
/**
 * @brief find the intersection of two forward_lists
 * NOTES:
 * 1. Running time complexity: O(N + M)
 * 2. Space O(N) or O(M)
 * @param input1_node pointer to the head of first list
 * @param input2_node pointer to the head of second list
 * @return std::shared_ptr<Forward_List_Node<T>> intersection of the two
 */
std::shared_ptr<Forward_List_Node<T>>
    intersection_hash( std::shared_ptr<Forward_List_Node<T>> input1_node,
                       std::shared_ptr<Forward_List_Node<T>> input2_node ) {

    std::unordered_set<std::shared_ptr<Forward_List_Node<T>>> input1_nodes;
    while ( input1_node != nullptr ) {
        input1_nodes.insert( input1_node );
        input1_node = input1_node->next_;
    }

    while ( input2_node != nullptr ) {
        if ( input1_nodes.find( input2_node ) != input1_nodes.end() ) return input2_node;
        input2_node = input2_node->next_;
    }

    return nullptr;
}

/**
 * @brief Get the tail and size object
 * Helper function
 *
 * @tparam T
 * @param root
 * @return std::pair<std::shared_ptr<Forward_List_Node<T>>, size_t>
 */
template <typename T>
std::pair<std::shared_ptr<Forward_List_Node<T>>, size_t>
    get_tail_and_size( std::shared_ptr<Forward_List_Node<T>> root ) {
    size_t size = 0;
    while ( root && root->next_ ) {
        root = root->next_;
        ++size;
    }
    return std::make_pair( root, size );
}

/**
 * @brief Returns the nth node from the start pointer
 * Helper function
 * @tparam T
 * @param root
 * @param n
 * @return std::shared_ptr<Forward_List_Node<T>>
 */
template <typename T>
std::shared_ptr<Forward_List_Node<T>> nth_node( std::shared_ptr<Forward_List_Node<T>> root,
                                                size_t n ) {
    while ( n > 0 && root ) {
        root = root->next_;
        --n;
    }
    return root;
}

/**
 * @brief find the intersection of two forward_lists
 * NOTES:
 * 1. Running time complexity: O(N + M)
 * 2. Space O(1)
 * @param input1_node pointer to the head of first list
 * @param input2_node pointer to the head of second list
 * @return std::shared_ptr<Forward_List_Node<T>> intersection of the two
 */
template <typename T>
std::shared_ptr<Forward_List_Node<T>>
    find_intersection( std::shared_ptr<Forward_List_Node<T>> input1_node,
                       std::shared_ptr<Forward_List_Node<T>> input2_node ) {
    // Empty lists
    if ( !input1_node || !input2_node ) return nullptr;

    auto tail_size_1 = get_tail_and_size( input1_node );
    auto tail_size_2 = get_tail_and_size( input2_node );

    // Tails are not equal
    if ( tail_size_1.first != tail_size_2.first ) return nullptr;

    // Start from the equal size
    auto shorter = tail_size_1.second < tail_size_2.second ? input1_node : input2_node;
    auto longer  = tail_size_1.second < tail_size_2.second ? input2_node : input1_node;

    longer = nth_node( longer, abs( tail_size_1.second - tail_size_2.second ) );

    while ( shorter != longer ) {
        shorter = shorter->next_;
        longer  = longer->next_;
    }

    return longer;
}
} // namespace algorithm