/**
 * @brief List of Depths
 * Given a binary tree, design an algorithm which creates a linked list of all the nodes at each
 * depth (e.g., if you have a tree with depth D, you'll have D linked lists).
 *
 * @file list_depths.h
 * @author Tushar Chugh
 */

#pragma once

#include <forward_list>
#include <vector>
#include "bst.h"

namespace algorithm {

using node_pointer = typename bst<int>::node_raw_pointer;

void list_depth( node_pointer node, size_t depth, std::vector<std::forward_list<int>>& output,
                 node_pointer end );

/**
 * Algorithm will work for any binary try but as this repo as bst implemented, so using that
 * @param input binary tree
 * @return list of depths
 */
std::vector<std::forward_list<int>> list_depth( bst<int>& input ) {
    std::vector<std::forward_list<int>> output;
    list_depth( input.root(), 0, output, input.end_pointer() );
    return output;
}

void list_depth( node_pointer node, size_t depth, std::vector<std::forward_list<int>>& output,
                 node_pointer end ) {
    if ( node == nullptr || node == end ) return;
    if ( depth == output.size() ) output.push_back( std::forward_list<int>{} );
    output.at( depth ).push_front( node->value_ );
    list_depth( ( node->left_ ).get(), depth + 1, output, end );
    list_depth( ( node->right_ ).get(), depth + 1, output, end );
}
} // namespace algorithm