#include "include/trees_graphs/common_ancestor.h"
#include <gtest/gtest.h>

#include <iostream>

TEST( COMMON_ANCESTOR, ROOT ) {
    algorithm::bst<int> tree = {50, 40, 60, 30, 45, 55, 70, 20, 35};
    auto root                = tree.root();
    ASSERT_EQ( root, algorithm::first_common_ancestor( root, root ) );
}

TEST( COMMON_ANCESTOR, SAME_LENGTH_SAME_SIDE ) {
    algorithm::bst<int> tree = {50, 40, 60, 30, 45, 55, 70, 20, 35};
    auto first               = ( ( tree.root()->left_ )->left_ ).get();  // 30
    auto second              = ( ( tree.root()->left_ )->right_ ).get(); // 45
    ASSERT_EQ( ( ( tree.root() )->left_ ).get(),
               algorithm::first_common_ancestor( first, second ) );
}

TEST( COMMON_ANCESTOR, SAME_LENGTH_DIFFERENT_SIDE ) {
    algorithm::bst<int> tree = {50, 40, 60, 30, 45, 55, 70, 20, 35};
    auto first               = ( ( tree.root()->left_ )->left_ ).get();   // 30
    auto second              = ( ( tree.root()->right_ )->right_ ).get(); // 70
    ASSERT_EQ( tree.root(), algorithm::first_common_ancestor( first, second ) );
}

TEST( COMMON_ANCESTOR, DIFFERENT_LENGTH_SAME_SIDE ) {
    algorithm::bst<int> tree = {50, 40, 60, 30, 45, 55, 70, 20, 35};
    auto first               = ( ( tree.root()->left_ )->left_->left_ ).get(); // 20
    auto second              = ( ( tree.root()->left_ )->right_ ).get();       // 45
    ASSERT_EQ( ( ( tree.root() )->left_ ).get(),
               algorithm::first_common_ancestor( first, second ) );
}
