#include <gtest/gtest.h>
#include <trees_graphs/check_balanced.h>

TEST(CHECK_BALANCED, EMPTY) {
    algorithm::bst<int> input;
    ASSERT_TRUE(algorithm::is_balanced(input));
}

TEST(CHECK_BALANCED, FIVE_ELEMENTS) {
    algorithm::bst<int> input = {3, 2, 5, 4, 1};
    ASSERT_TRUE(algorithm::is_balanced(input));
}

TEST(CHECK_BALANCED, SEVEN_ELEMENTS) {
    algorithm::bst<int> input = {4, 2, 6, 1, 3, 5, 7};
    ASSERT_TRUE(algorithm::is_balanced(input));
}

TEST(CHECK_BALANCED, UNBALANCED_ELEMENTS) {
    algorithm::bst<int> input = {1, 2, 3, 4, 5, 6};
    ASSERT_FALSE(algorithm::is_balanced(input));
}
