#include <gtest/gtest.h>
#include "include/trees_graphs/successor.h"

/**
 *             40
 *            /  \
 *          20   50
 *         / \   / \
 *        10 25 45 55
 *       / \      / \
 *         15       60
 */

TEST(SUCCESSOR, DEMO) {
    auto init_list = {40, 20, 25, 50, 55, 45, 10, 15, 60};
    auto root = algorithm::insert(init_list);
    // 40
    ASSERT_EQ(45, algorithm::successor(root)->value);
    // 15
    ASSERT_EQ(20, algorithm::successor(root->left->left->right)->value);
    // 10
    ASSERT_EQ(15, algorithm::successor(root->left->left)->value);
    // 20
    ASSERT_EQ(25, algorithm::successor(root->left)->value);
    // 25
    ASSERT_EQ(40, algorithm::successor(root->left->right)->value);
    // 50
    ASSERT_EQ(55, algorithm::successor(root->right)->value);
    // 45
    ASSERT_EQ(50, algorithm::successor(root->right->left)->value);
    // 55
    ASSERT_EQ(60, algorithm::successor(root->right->right)->value);
    // 60
    ASSERT_EQ(nullptr, algorithm::successor(root->right->right->right));
}