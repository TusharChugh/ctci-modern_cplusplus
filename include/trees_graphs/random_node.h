/**
 * @brief Random Node
 * You are implementing a binary search tree class from scratch, which, in addition to insert, find,
 * and delete, has a method getRandomNode() which returns a random node from the tree. All nodes
 * should be equally likely to be chosen. Design and implement an algorithm for get Ra ndomNode, and
 * explain how you would implement the rest of the methods.
 *
 * @file random_node.h
 * @author Tushar Chugh
 */

#pragma once

#include <random>
#include "bst.h"

#include <iostream>

namespace algorithm {
template <typename T> auto get_random_node( const bst<T>& tree ) {
    std::mt19937 generator( 31556431 );
    std::uniform_int_distribution<> distribution( 0, tree.size() - 1 );
    auto random_node = tree.begin();
    auto distance    = distribution( generator );
    while ( distance ) {
        ++random_node;
        --distance;
    }
    return random_node;
}
} // namespace algorithm