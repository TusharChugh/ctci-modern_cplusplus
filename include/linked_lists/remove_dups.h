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

#include <iostream>

namespace algorithm {
template<class T> void remove_duplicates_map( Forward_List<T>& input ) {
    std::cout << "hello";
    auto head = input.begin();

    std::unordered_set<T> seen_elements;

    while ( head != nullptr ) {
        if ( seen_elements.find( head->value_ ) != seen_elements.end() ) {
            seen_elements.insert( head->value_ );
            head = head->next_;
        } else {
            head->next_ = head->next_->next_;
        }
    }
}
} // namespace algorithm
