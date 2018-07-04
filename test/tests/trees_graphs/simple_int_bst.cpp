#include <gtest/gtest.h>
#include "include/trees_graphs/simple_int_bst.h"

TEST(SIMPLE_INT_BST, DEMO) {
    auto init_list = {40, 20, 50, 10, 60};
    auto root = algorithm::insert(init_list);
//    ASSERT_EQ(40, root->value);
    ASSERT_EQ(40, algorithm::insert(nullptr, 40)->value);
}