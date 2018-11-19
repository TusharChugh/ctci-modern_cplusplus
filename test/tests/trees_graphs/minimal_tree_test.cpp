#include <trees_graphs/minimal_tree.h>
#include <gtest/gtest.h>

TEST( MINIMAL_TREE, DEMO ) {
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8};
    auto root              = algorithm::create_minimal_tree( input );

    ASSERT_EQ( 4, root->value_ );

    auto left  = root->left_;
    auto right = root->right_;
    ASSERT_EQ( 2, left->value_ );
    ASSERT_EQ( 6, right->value_ );

    auto left1  = left->left_;
    auto right1 = left->right_;
    ASSERT_EQ( 1, left1->value_ );
    ASSERT_EQ( 3, right1->value_ );

    auto left2  = right->left_;
    auto right2 = right->right_;
    ASSERT_EQ( 5, left2->value_ );
    ASSERT_EQ( 7, right2->value_ );
}

TEST( MINIMAL_TREE, EMPTY_INPUT ) {
    std::vector<int> input;
    ASSERT_EQ( nullptr, algorithm::create_minimal_tree( input ) );
}