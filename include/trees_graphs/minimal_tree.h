/**
 * @brief Minimal Tree
 * Given a  sorted (increasing order)  array with unique integer elements,  write an algorithm to
 * create a binary search tree with minimal height.
 *
 * @file minimal_tree.h
 * @author Tushar Chugh
 */

#pragma once

#include <stddef.h>
#include <vector>

namespace algorithm {
struct bst_node {
    using node_pointer = bst_node*;

    explicit bst_node( int value = 0 ) : value_{value}, left_{nullptr}, right_{nullptr} {}

    ~bst_node() = default;

    int value_;
    node_pointer left_;
    node_pointer right_;
};

using node_pointer = bst_node*;

node_pointer create_minimal_tree( const std::vector<int>& input, int begin, int end );

node_pointer create_minimal_tree( const std::vector<int>& input ) {
    return create_minimal_tree( input, 0, input.size() - 1 );
}

node_pointer create_minimal_tree( const std::vector<int>& input, int begin, int end ) {
    if ( end < begin ) return nullptr;
    int mid      = ( begin + end ) / 2;
    auto node    = new bst_node( input.at( mid ) );
    node->left_  = create_minimal_tree( input, begin, mid - 1 );
    node->right_ = create_minimal_tree( input, mid + 1, end );
    return node;
}
} // namespace algorithm