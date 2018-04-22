/**
 * @brief Return Kth to Last
 * Implement an algorithm to find the kth to last element of a singly linked list
 *
 * @file kth_tolast.h
 * @author Tushar Chugh
 */

#pragma once

#include "forward_list.h"

namespace algorithm {

template<class T>
std::shared_ptr<Forward_List_Node<T>> kth_tolast_runner( Forward_List<T>& input, size_t k ) {
    auto runner1 = input.front();
    auto runner2 = input.front();

    for ( size_t index = 0; index < k; ++index ) {
        if ( runner2 == nullptr ) return nullptr;
        runner2 = runner2->next_;
    }

    while ( runner2 != nullptr ) {
        runner2 = runner2->next_;
        runner1 = runner1->next_;
    }
    return runner1;
}
} // namespace algorithm