#include <gtest/gtest.h>
#include "include/sorting_searching/find_duplicates.h"

TEST(FIND_DUPLICATES, THREE_DUPS_TENTOTAL) {
    std::vector<int> input = {1, 5, 3, 2, 4, 3, 6, 3, 10, 11};
    std::unordered_set<int> expected_output = {3};
    ASSERT_EQ(expected_output, algorithm::find_duplicates(input));
}

TEST(FIND_DUPLICATES, MULTIPLE_DUPS_TENTOTAL) {
    std::vector<int> input = {1, 5, 3, 2, 4, 3, 6, 3, 2, 5};
    std::unordered_set<int> expected_output = {3, 2, 5};
    ASSERT_EQ(expected_output, algorithm::find_duplicates(input));
}

TEST(FIND_DUPLICATES, NO_DUPS) {
    std::vector<int> input = {1, 5, 3, 2, 4};
    ASSERT_TRUE(algorithm::find_duplicates(input).empty());
}

TEST(FIND_DUPLICATES, EMPTY) {
    std::vector<int> input;
    ASSERT_TRUE(algorithm::find_duplicates(input).empty());
}