/**
 * @brief Sorted Merge: You are given two sorted arrays, A and B, where A has a large enough buffer
 * at the end to hold B. Write a method to merge B into A in sorted order.
 *
 * @file sorted_merge.h
 * @author Tushar Chugh
 */

#pragma once

#include <vector>

namespace algorithm {
void sorted_merge( std::vector<int>& A, const std::vector<int>& B, int last_a, int last_b ) {
    int merged_index = A.size() - 1;
    while ( last_b >= 0 ) {
        if ( last_a >= 0 && A[last_a] > B[last_b] ) {
            A[merged_index] = A[last_a];
            --last_a;
        } else {
            A[merged_index] = B[last_b];
            --last_b;
        }
        --merged_index;
    }
}

void sorted_merge( std::vector<int>& A, const std::vector<int>& B, int num_elements_a ) {
    sorted_merge( A, B, num_elements_a - 1, B.size() - 1 );
}
} // namespace algorithm