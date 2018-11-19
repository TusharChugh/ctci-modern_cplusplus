#include <sorting_searching/sorted_matrix_search.h>
#include <gtest/gtest.h>

TEST(SORTED_MATRIX, EQUAL_SIZE) {
    std::vector<std::vector<int>> input = {{15, 20, 40, 85}, {20, 35, 80, 95}, {30, 55, 90, 105}, {40, 80, 100, 120}};
    const auto expected_output = std::make_pair(2, 1);
    ASSERT_EQ(expected_output, algorithm::find_element(input, 55));
}

TEST(SORTED_MATRIX, UNEQUAL_SIZE) {
    std::vector<std::vector<int>> input = {{15, 20, 40, 85}, {20, 35, 80, 95}, {30, 55, 90, 105}};
    const auto expected_output = std::make_pair(2, 3);
    ASSERT_EQ(expected_output, algorithm::find_element(input, 105));
}