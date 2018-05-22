/**
 * @brief Validate BST
 * Implement a function to check if a binary tree is a binary search tree.
 *
 * @file validate_bst.h
 * @author Tushar Chugh
 */

#pragma once

#include "bst.h"

namespace algorithm {
// Note: we will modify the bst class for both bst and non-bst test cases
template <typename T> bool is_bst( bst_node<T>* node, T min, T max, bst_node<T>* end ) {
    if ( node == nullptr || node == end ) return true;

    if ( node->value_ < min || node->value_ > max ) return false;

    return ( is_bst( ( node->left_ ).get(), min, node->value_, end ) &&
             is_bst( ( node->right_ ).get(), node->value_, max, end ) );
}

/**
 * @brief checks if a binary tree is a bst
 * NOTE: Did a bit of checting to use bst as binary tree by accessing the raw pointers and modifying
 * the value
 * Could have used comparator as opposed to < operator but wanted to keep things simple
 * @tparam T Dtype
 * @param input input binary tree
 * @param min minimum possible value of type T (not in the tree)
 * @param max maximum possible value of type T (not in the tree)
 * @return true if input is bst
 * @return false if input is not bst
 */
template <typename T> bool is_bst( const bst<T>& input, T min, T max ) {
    return is_bst( input.root(), min, max, input.end_pointer() );
}

/**
 * @brief checks if a binary tree is a bst
 * Note:
 * Used the iterators implemented in the bst class
 * iterative solution
 * O(n) running time (considering begin() is cached)
 * O(1) extra memory
 * successor is implemented as inorder traversal
 * @tparam T Dtype
 * @param input input bst
 * @param min min possible value of type t (less than leftmost element)
 * @return true if input is bst
 * @return false if input is not bst
 */
template <typename T> bool is_bst_successor( const bst<T>& input, T min ) {
    T previous = min;
    for ( const auto& element : input ) {
        if ( element < previous ) return false;
        previous = element;
    }
    return true;
}

} // namespace algorithm