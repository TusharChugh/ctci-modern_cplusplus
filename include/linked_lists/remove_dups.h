/**
 * @brief Remove Dups
 * Write code to remove duplicates from an unsorted linked list
 *
 * @file remove_dups.h
 * @author Tushar Chugh
 */

#pragma once

#include <unordered_set>
#include "forward_list.h"

namespace algorithm {
template<class T> void remove_duplicates_map( Forward_List<T>& input ) {
    auto head = input.begin();
    if ( head == nullptr ) return;

    std::unordered_set<T> seen_elements;

    while ( head != nullptr && head->next_ != nullptr ) {
        seen_elements.insert( head->value_ );
        if ( seen_elements.find( head->next_->value_ ) != seen_elements.end() ) {
            head->next_ = (head->next_)->next_;
        }
        head = head->next_;
    }
}
} // namespace algorithm
