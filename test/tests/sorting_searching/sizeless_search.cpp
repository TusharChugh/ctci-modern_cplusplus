#include <gtest/gtest.h>
#include <sorting_searching/sizeless_search.h>

TEST(SIZELESS_SEARCH, FIVE_ELEMENTS) {
    std::vector<int> input_v = {1, 2, 4, 8, 10};
    algorithm::sizeless_vector input(input_v);
    ASSERT_EQ(0, algorithm::find_element(input, 1));
    ASSERT_EQ(1, algorithm::find_element(input, 2));
    ASSERT_EQ(2, algorithm::find_element(input, 4));
    ASSERT_EQ(3, algorithm::find_element(input, 8));
    ASSERT_EQ(4, algorithm::find_element(input, 10));
}