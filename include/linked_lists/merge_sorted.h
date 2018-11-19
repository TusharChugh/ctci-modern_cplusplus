#pragma once

#include <linked_lists/simple_int_list.h>

namespace algorithm {
    List_Node* merge_sorted(List_Node* head1, List_Node* head2) {
        List_Node* result = new List_Node();
        List_Node* result_head = result;

        while(head1 && head2) {
            if(head1->val <= head2->val){
                result->next = head1;
                head1 = head1->next;
            }
            else {
                result->next = head2;
                head2 = head2->next;
            }
            result = result->next;
        }

        if(head1) {
            result ->next = head1;
        }
        if(head2) {
            result ->next = head2;
        }

        return result_head->next;
    }
}