/**
 * @brief First Common Ancestor
 * Design an algorithm and write code to find the first common ancestor of two nodes in a  binary
 * tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary
 * search tree.
 *
 * @file common_ancestor.h
 * @author Tushar Chugh
 */

#pragma once

#include "bst.h"

#include <iostream>

namespace algorithm {

template <typename T> size_t height( bst_node<T>* node ) {
    size_t height = 0;
    while ( node ) {
        node = node->parent_;
        ++height;
    }
    return height;
}

template <typename T> bst_node<T>* go_up_by( bst_node<T>* node, int n ) {
    while ( n > 0 && node ) {
        node = node->parent_;
        --n;
    }
    return node;
}

template <typename T> bst_node<T>* first_common_ancestor( bst_node<T>* p, bst_node<T>* q ) {
    int delta           = height( p ) - height( q );
    auto shallower_node = delta > 0 ? q : p;
    auto deeper_node    = delta > 0 ? p : q;

    deeper_node = go_up_by( deeper_node, abs( delta ) );

    while ( shallower_node != deeper_node && shallower_node && deeper_node ) {
        shallower_node = shallower_node->parent_;
        deeper_node    = deeper_node->parent_;
    }
    return ( !shallower_node || !deeper_node ) ? nullptr : shallower_node;
}
} // namespace algorithm