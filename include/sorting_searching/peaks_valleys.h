/**
 * @brief Peaks and Valleys: In an array of integers, a "peak" is an element which is greater than
 * or equal to the adjacent integers and a "valley" is an element which is less than or equal to the
 * adjacent integers.
 * For example, in the array {5, 8, 6, 2, 3, 4, 6}, {8, 6} are peaks and {S, 2} are valleys. Given
 * an array
 * of integers, sort the array into an alternating sequence of peaks and valleys.
 * EXAMPLE
 * Input: {5, 3, 1, 2, 3}
 * Output: {5, 1, 3, 2, 3}
 *
 * @file peaks_valleys.h
 * @author Tushar Chugh
 */

#pragma once

#include <algorithm>
#include <vector>

namespace algorithm {
void peaks_valleys_sort( std::vector<int>& input ) {
    std::sort( input.begin(), input.end() );

    for ( size_t index = 1; index < input.size(); index += 2 ) {
        std::swap( input[index], input[index - 1] );
    }
}
} // namespace algorithm