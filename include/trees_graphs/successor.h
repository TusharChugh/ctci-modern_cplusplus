/**
 * @brief Successor Write an algorithm to find the "next" node (i.e., in-order successor) of a given
 * node in a binary search tree. You may assume that each node has a link to its parent.
 *
 * @file successor.h
 * @author Tushar Chugh
 */

// Note1: Already implemented in the bst iterator implementation

#pragma once
//Implementation with simple_int_bst

#include <trees_graphs/simple_int_bst.h>

namespace algorithm {
    bst_int_node* min_tree(bst_int_node* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    bool is_left_child(bst_int_node* node) {
        if(!(node->parent)) return true;
            return node->parent->left == node;
    }

    bst_int_node* successor(bst_int_node* node) {
        if(!node) return nullptr;
        if(node->right) return min_tree(node->right);
        while (!is_left_child(node)) {
            node = node->parent;
        }
        return node->parent;
    }
}

