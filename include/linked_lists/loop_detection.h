/**
 * @brief Loop Detection
 * Given a circular linked list, implement an algorithm that returns the node at the beginning of
 * the loop. DEFINITION Circular linked list: A (corrupt) linked list in which a node's next pointer
 * points to an earlier node, so as to make a loop in the linked list.
 *
 * EXAMPLE Input: A -> B -> C -> D  -> E  -> C [the same C as earlier)
 * Output: C
 *
 * @file loop_detection.h
 * @author Tushar Chugh
 */

#pragma once
#include "forward_list.h"

namespace algorithm {
template<typename T>
std::shared_ptr<Forward_List_Node<T>> find_loop( std::shared_ptr<Forward_List_Node<T>> input ) {
    std::shared_ptr<Forward_List_Node<T>> result = nullptr;
}
} // namespace algorithm