/**
 * @brief Check Subtree
 * T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an algorithm to
 * determine if T2 is a subtree of T1. A tree T2 is a subtree of T1 if there exists a node n in Tl
 * such that the subtree of n is identical to T2. That is, if you cut off the tree at node n, the
 * two trees would be identical.
 *
 * @file check_subtree.h
 * @author Tushar Chugh
 */

#pragma once

#include <sstream>
#include <string>
#include "bst.h"

namespace algorithm {

/**
 * @brief Helper method to convert bst to string (treating X as nullptr)
 *
 * @param node root of the tree/sub-tree
 * @param end_node of the bst
 * @param output string
 */
void stringify_tree( bst_node<int>* node, bst_node<int>* end_node, std::stringstream& output ) {
    if ( node == nullptr || node == end_node ) {
        output << "X";
        return;
    }
    output << node->value_;
    stringify_tree( ( node->left_ ).get(), end_node, output );
    stringify_tree( ( node->right_ ).get(), end_node, output );
}

/**
 * @brief determine if input is the subtree of the tree
 * Notes:
 * 1. Run time complexity: O(N + M)
 * 2. Space complexity: O (N + M)
 * 3. BST implemenet defined in bst.h is used but algo works for binary tree in general
 * 4. bst implementation has end node, so that needs to be handled
 * @param tree input tree
 * @param sub_tree sub tree (to be evaluated)
 * @return true if substree
 * @return false if not subtree
 */
bool is_subtree( const bst<int>& tree, const bst<int>& sub_tree ) {
    std::stringstream tree_string;
    std::stringstream sub_tree_string;
    stringify_tree( tree.root(), tree.end_pointer(), tree_string );
    stringify_tree( sub_tree.root(), sub_tree.end_pointer(), sub_tree_string );
    return ( ( tree_string.str() ).find( sub_tree_string.str() ) != std::string::npos );
}
} // namespace algorithm