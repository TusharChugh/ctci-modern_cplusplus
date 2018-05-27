/**
 * @brief Paths with Sum
 * You are given a  binary tree in which each node contains an integer value (which might be
 * positive or negative). Design an algorithm to count the number of paths that sum to a given
 * value. The path does not need to start or end at the root or a leaf, but it must go downwards
 * (traveling only from parent nodes to child nodes).
 *
 * @file paths_sum.h
 * @author Tushar Chugh
 */

#pragma once

#include "bst.h"

namespace algorithm {
int path_with_sum_node( bst_node<int>* node, bst_node<int>* end_node, int target_sum,
                        int current_sum ) {
    if ( node == nullptr || node == end_node ) return 0;
    current_sum += node->value_;

    int total_paths = 0;
    if ( current_sum == target_sum ) ++total_paths;

    total_paths += path_with_sum_node( ( node->left_ ).get(), end_node, target_sum, current_sum );
    total_paths += path_with_sum_node( ( node->right_ ).get(), end_node, target_sum, current_sum );
    return total_paths;
}

int path_with_sum_naive_helper( bst_node<int>* node, bst_node<int>* end_node, int target_sum ) {
    if ( node == nullptr || node == end_node ) return 0;

    int paths_from_root = path_with_sum_node( node, end_node, target_sum, 0 );
    int paths_on_left   = path_with_sum_naive_helper( ( node->left_ ).get(), end_node, target_sum );
    int paths_on_right = path_with_sum_naive_helper( ( node->right_ ).get(), end_node, target_sum );

    return paths_from_root + paths_on_left + paths_on_right;
}

/**
 * @brief brute force solution to count paths with target sum
 *
 * @param tree tree object
 * @param target_sum
 * @return int counts with paths equals target sum
 */
int path_with_sum_naive( const bst<int>& tree, int target_sum ) {
    if ( tree.empty() ) return 0;
    return path_with_sum_naive_helper( tree.root(), tree.end_pointer(), target_sum );
}
} // namespace algorithm