#pragma once

#include <vector>

namespace algorithm {
    int binary_search(const std::vector<int>& input, int element, int left, int right) {
        int mid = (left + right) / 2;

        if (input[mid] == element) return mid;

        if(right < left) return -1;

        if (element < input[mid]) return binary_search(input, element, left, mid - 1);

        else return binary_search(input, element, mid + 1, right);
    }

    int binary_search(const std::vector<int>& input, int element) {
        return binary_search(input, element, 0, input.size() - 1);
    }
}