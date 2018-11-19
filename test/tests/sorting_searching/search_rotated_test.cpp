#include <gtest/gtest.h>
#include <sorting_searching/search_rotated.h>

TEST(SEARCH_ROTATED, DEMO) {
    std::vector<int> input = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    ASSERT_EQ(8, algorithm::search_rotated(input, 5));
}

TEST(SEARCH_ROTATED, FIRST_ELEMENT) {
    std::vector<int> input = {10, 15, 20, 0, 5};
    ASSERT_EQ(0, algorithm::search_rotated(input, 10));
}

TEST(SEARCH_ROTATED, LAST_ELEMENT) {
    std::vector<int> input = {10, 15, 20, 0, 5};
    ASSERT_EQ(4, algorithm::search_rotated(input, 5));
}

TEST(SEARCH_ROTATED, MID_ELEMENT) {
    std::vector<int> input = {10, 15, 20, 0, 5};
    ASSERT_EQ(2, algorithm::search_rotated(input, 20));
}

TEST(SEARCH_ROTATED, BETWEEN1) {
    std::vector<int> input = {50, 5, 20, 30, 40};
    ASSERT_EQ(1, algorithm::search_rotated(input, 5));
}

TEST(SEARCH_ROTATED, BETWEEN2) {
    std::vector<int> input = {50, 5, 20, 30, 40};
    ASSERT_EQ(3, algorithm::search_rotated(input, 30));
}

