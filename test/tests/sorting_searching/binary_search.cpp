#include <include/gtest/gtest.h>
#include "include/sorting_searching/binary_search.h"

TEST(BINARY_SEARCH, FIVE_ELEMENTS) {
    std::vector<int> input = {1, 2, 4, 8, 10};
    ASSERT_EQ(0, algorithm::binary_search(input, 1));
    ASSERT_EQ(1, algorithm::binary_search(input, 2));
    ASSERT_EQ(2, algorithm::binary_search(input, 4));
    ASSERT_EQ(3, algorithm::binary_search(input, 8));
    ASSERT_EQ(4, algorithm::binary_search(input, 10));
}