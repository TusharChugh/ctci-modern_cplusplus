#include "include/trees_graphs/validate_bst.h"
#include <gtest/gtest.h>
#include <limits>

TEST( VALIDATE_BST, DEMO_MIN_MAX ) {
    algorithm::bst<int> input = {3, 2, 5, 4, 1};
    ASSERT_TRUE( algorithm::is_bst( input, std::numeric_limits<int>::min(),
                                    std::numeric_limits<int>::max() ) );
}

TEST( VALIDATE_BST, DEMO_SUCCESSOR ) {
    algorithm::bst<int> input = {3, 2, 5, 4, 1};
    ASSERT_TRUE( algorithm::is_bst_successor( input, std::numeric_limits<int>::min() ) );
}

TEST( VALIDATE_BST, MIN_MAX_FAILURE ) {
    algorithm::bst<int> input                  = {3, 2, 5, 4, 1};
    ( ( input.root()->right_ ).get() )->value_ = 0;
    ASSERT_FALSE( algorithm::is_bst( input, std::numeric_limits<int>::min(),
                                     std::numeric_limits<int>::max() ) );
}

TEST( VALIDATE_BST, SUCCESSOR_FAILURE ) {
    algorithm::bst<int> input                 = {3, 2, 5, 4, 1};
    ( ( input.root()->left_ ).get() )->value_ = 10;
    ASSERT_FALSE( algorithm::is_bst_successor( input, std::numeric_limits<int>::min() ) );
}