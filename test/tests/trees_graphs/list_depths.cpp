#include <gtest/gtest.h>
#include "include/trees_graphs/list_depths.h"

TEST(LIST_DEPTH, FIVE_ELEMENTS) {
    algorithm::bst<int> input = {3, 2, 5, 4, 1};
    std::vector<std::forward_list<int>> expected_output = {{3}, {5, 2}, {4, 1}};
    const auto& output = algorithm::list_depth(input);
    ASSERT_EQ(expected_output, output);
}

TEST(LIST_DEPTH, EMPTY) {
    algorithm::bst<int> input;
    std::vector<std::forward_list<int>> expected_output = {};
    const auto& output = algorithm::list_depth(input);
    ASSERT_EQ(expected_output, output);
}