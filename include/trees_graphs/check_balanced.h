/**
 * @brief Check Balanced
 * Implement a function to check if a  binary tree is balanced. For the purposes of this question, a
 * balanced tree is defined to be a tree such that the heights of the two subtrees of any node never
 * differ by more than one.
 *
 * @file check_balanced.h
 * @author Tushar Chugh
 */

#pragma once

#include <cmath>
#include "include/trees_graphs/bst.h"

namespace algorithm {

template <typename T> size_t get_height( bst_node<T>* node, bst_node<T>* end ) {
    if ( node == nullptr || node == end ) return 0;
    return get_height( ( node->left_ ).get(), end ) + get_height( ( node->right_ ).get(), end ) + 1;
}

template <typename T> bool is_balanced( const bst<T>& input ) {
    if ( input.empty() ) return true;
    auto root = input.root();
    return !( std::abs( get_height( ( root->left_ ).get(), input.end_pointer() ) -
                        get_height( ( root->right_ ).get(), input.end_pointer() ) ) > 1 );
}
} // namespace algorithm