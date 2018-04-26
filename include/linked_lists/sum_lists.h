/**
 * @brief Sum Lists
 * You have two numbers represented by a linked list, where each node contains a single digit. The
 * digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
 * function that adds the two numbers and returns the sum as a linked list.
 * EXAMPLE Input: (7-> 1 -> 6) + (5 -> 9 -> 2).Thatis,617 + 295.
 * Output:  2 -> 1 -? 9. That is, 912.
 *
 * FOLLOW UP Suppose the digits are stored in forward order. Repeat the above problem.
 * EXAMPLE Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).Thatis,617 + 295.
 * Output: 9 -> 1 -> 2. That is, 912.
 *
 * @file sum_lists.h
 * @author Tushar Chugh
 */
#pragma once

#include <iostream>
#include "forward_list.h"

namespace algorithm {
using int_node_pointer = typename std::shared_ptr<Forward_List_Node<int>>;
int_node_pointer sum_lists( int_node_pointer head1, int_node_pointer head2 ) {
    int_node_pointer result_head = nullptr;
    int_node_pointer result_tail = nullptr;
    int carry                    = 0;

    while ( head1 != nullptr || head2 != nullptr || carry ) {
        auto head1_value = ( head1 == nullptr ) ? 0 : head1->value_;
        auto head2_value = ( head2 == nullptr ) ? 0 : head2->value_;

        auto sum      = head1_value + head2_value + carry;
        auto sum_node = std::make_shared<Forward_List_Node<int>>( sum % 10 );

        if ( result_head == nullptr )
            result_head = sum_node;
        else
            result_tail->next_ = sum_node;

        result_tail = sum_node;
        carry       = sum / 10;

        if ( head1 != nullptr ) head1 = head1->next_;
        if ( head2 != nullptr ) head2 = head2->next_;
    }
    return result_head;
}

// ToDo: add recussive solution and a case if digits are stored in forward order

} // namespace algorithm