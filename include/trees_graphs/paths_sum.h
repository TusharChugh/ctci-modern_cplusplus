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

#include <unordered_map>
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

void increment_hash_map( std::unordered_map<int, int>& path_count, int key, int delta ) {
    auto paths = path_count.find( key );
    if ( paths != path_count.end() ) {
        if ( paths->second + delta == 0 )
            path_count.erase( key );
        else {
            paths->second += delta;
        }
        return;
    }
    path_count.insert( std::make_pair( key, delta ) );
}

int path_with_running_sum_helper( bst_node<int>* node, bst_node<int>* end_node, int target_sum,
                                  int running_sum, std::unordered_map<int, int>& path_count ) {
    if ( node == nullptr || node == end_node ) return 0;

    running_sum += node->value_;
    int total_paths                              = 0;
    auto paths                                   = path_count.find( running_sum - target_sum );
    if ( paths != path_count.end() ) total_paths = paths->second;

    if ( running_sum == target_sum ) ++total_paths;

    increment_hash_map( path_count, running_sum, 1 );
    total_paths += path_with_running_sum_helper( ( node->left_ ).get(), end_node, target_sum,
                                                 running_sum, path_count );
    total_paths += path_with_running_sum_helper( ( node->right_ ).get(), end_node, target_sum,
                                                 running_sum, path_count );
    increment_hash_map( path_count, running_sum, -1 );
    return total_paths;
}

/**
 * @brief Solution to count paths with target sum
 * Uses running sum to optimize running time
 * @param tree tree object
 * @param target_sum
 * @return int counts with paths equals target sum
 */
int path_with_sum_running_sum( const bst<int>& tree, int target_sum ) {
    std::unordered_map<int, int> path_count;
    return path_with_running_sum_helper( tree.root(), tree.end_pointer(), target_sum, 0,
                                         path_count );
}

} // namespace algorithm