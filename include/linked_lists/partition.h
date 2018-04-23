/**
 * @brief Partition:
 * Write code to partition a linked list around a value x, such that all nodes less than x come
 * before all nodes greater than or equal to x. If x is contained within the list, the values of x
 * only need to be after the elements less than x (see below). The partition element x can appear
 * anywhere in the "right partition"; it does not need to appear between the left and right
 * partitions.
 *
 * EXAMPLE
 * Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
 * Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
 *
 * @file partition.h
 * @author Tushar Chugh
 */

#pragma once

#include <forward_list.h>

namespace algorithm {
template<typename T> Forward_List<T> partition_stable( Forward_List<T>& input, const T& key ) {
    Forward_List partioned;
    auto node       = input.front();
    auto before_end = nullptr;
    auto after_end  = nullptr;

    while ( node != nullptr ) {
        if ( node->value_ < key ) {
            // partition.push_back(node_va)
        }
    }

    return partitioned;
}
} // namespace algorithm