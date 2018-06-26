/**
 * Search in Rotated Array: Given a sorted array of n integers that has been rotated an unknown
number of times, write code to find an element in the array. You may assume that the array was
originally sorted in increasing order.
EXAMPLE
Input Find 5 in array {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}
Output 8 (the index of 5 in the array)
**/

#pragma once

#include <vector>

/**
 * pseudo
 *
 * while (first < last
 *
 * case 0: if mid == element return mid
 * case 1: if mid > first //sorted
 *  case 1.a: element is in between first and mid -> search left
 *  case 1.b: elements is not in between -> search right
 *
 * case 2:if mid < first
 *  case 2.a: elem is > first and < mid - search left
 *  case 2.b: search right
 *
 */

namespace algorithm {
    int search_rotated(const std::vector<int>& input, int elem, int first, int last) {
        int mid = (first + last)/2;

        if(input[mid] == elem) return mid;

        if(last < first) return -1;

        if(input[mid] > input[first]) {
            if(input[first] <= elem && elem < input[mid])
                return search_rotated(input, elem, first, mid - 1);
            else
                return search_rotated(input, elem, mid + 1, last);
        }
        else if (input[mid] < input[first]) {
            if(input[mid] < elem && elem <= input[last])
                return search_rotated(input, elem, mid + 1, last);
            else
                return search_rotated(input, elem, first, mid - 1);
        }
        else {
            if(input[mid] != input[last])
                return search_rotated(input, elem, mid + 1, last);
            else {
                int result = search_rotated(input, elem, first, mid - 1);
                if(result == -1)
                    return search_rotated(input, elem, mid + 1, last);
                return result;
            }
        }
    }

    int search_rotated(const std::vector<int>& input, int elem) {
        return search_rotated(input, elem, 0, input.size() - 1);
    }
}