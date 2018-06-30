/**
Sorted Search, No Size: You are given an array-like data structure Listy which lacks a size
method. It does, however, have an e lementAt (i) method that returns the element at index i in
0(1) time. If i is beyond the bounds of the data structure, it returns - 1. (For this reason, the data
structure only supports positive integers.) Given a Listy which contains sorted, positive integers,
find the index at which an element x occurs. If x occurs multiple times, you may return any index.
 **/

#pragma once

#include <vector>
#include <cstddef>

namespace  algorithm {
    class sizeless_vector {
    public:
        sizeless_vector(const std::vector<int>& input): input_(input) {}

        int element_at(size_t index) const noexcept {
            if(index >= input_.size()) return -1;
            else
                return input_[index];
        }

    private:
        std::vector<int> input_;
    };

    int binary_search(const sizeless_vector& input, int element, int left, int right) {
        int mid = (left + right) / 2;

        if (input.element_at(mid) == element) return mid;

        if(right < left) return -1;

        if (element < input.element_at(mid) || input.element_at(mid) == -1) return binary_search(input, element, left, mid - 1);

        else return binary_search(input, element, mid + 1, right);
    }

    int find_element(const sizeless_vector& input, int element) {
        int index = 1;
        while(input.element_at(index) != -1 && input.element_at(index) < element) {
            index = index * 2;
        }
        return binary_search(input, element, index/2, index);
    }
}