#include <trees_graphs/check_subtree.h>
#include <gtest/gtest.h>

TEST( CHECK_SUBTREE, FOUR_ELEMENTS_ROOT ) {
    algorithm::bst<int> tree     = {3, 4, 2, 1};
    algorithm::bst<int> sub_tree = {2, 1};
    ASSERT_TRUE( algorithm::is_subtree( tree, sub_tree ) );
}

TEST( CHECK_SUBTREE, FALSE_NOT_ELEMENTS ) {
    algorithm::bst<int> tree     = {3, 4, 2, 1};
    algorithm::bst<int> sub_tree = {2, 5};
    ASSERT_FALSE( algorithm::is_subtree( tree, sub_tree ) );
}

TEST( CHECK_SUBTREE, FALSE_ELEMENTS ) {
    algorithm::bst<int> tree     = {3, 4, 2, 1};
    algorithm::bst<int> sub_tree = {2, 4};
    ASSERT_FALSE( algorithm::is_subtree( tree, sub_tree ) );
}

TEST( CHECK_SUBTREE, FALSE_COMMON_ROOT ) {
    algorithm::bst<int> tree     = {3, 4, 2, 1};
    algorithm::bst<int> sub_tree = {3, 4};
    ASSERT_FALSE( algorithm::is_subtree( tree, sub_tree ) );
}

TEST( CHECK_SUBTREE, BOTH_EMPTY ) {
    algorithm::bst<int> tree;
    algorithm::bst<int> sub_tree;
    ASSERT_TRUE( algorithm::is_subtree( tree, sub_tree ) );
}

TEST( CHECK_SUBTREE, TREE_EMPTY ) {
    algorithm::bst<int> tree;
    algorithm::bst<int> sub_tree = {3, 4, 2, 1};
    ASSERT_FALSE( algorithm::is_subtree( tree, sub_tree ) );
}

TEST( CHECK_SUBTREE, SUBTREE_EMPTY ) {
    algorithm::bst<int> tree = {3, 4, 2, 1};
    algorithm::bst<int> sub_tree;
    ASSERT_TRUE( algorithm::is_subtree( tree, sub_tree ) );
}