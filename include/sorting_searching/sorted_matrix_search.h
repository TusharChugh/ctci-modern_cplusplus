/**
 * @brief Sorted Matrix Search: Given an M x N matrix in which each row and each column is sorted in
 * ascending order, write a method to find an element.
 *
 * @file sorted_matrix_search.h
 * @author Tushar Chugh
 */

#pragma once

#include <cstddef>
#include <utility>
#include <vector>

namespace algorithm {
    std::pair<int, int> find_element(const std::vector<std::vector<int>>& matrix, int element) {
        int row = 0;
        int col = matrix[0].size() - 1;

        while (row > matrix.size() || col >= 0) {
            if(matrix[row][col] == element) return std::make_pair(row, col);
            if(matrix[row][col] > element) --col;
            if(matrix[row][col] < element) ++row;
        }
        return std::make_pair(-1, -1);
    }
}