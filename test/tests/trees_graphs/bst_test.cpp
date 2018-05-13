#include "include/trees_graphs/bst.h"
#include <gtest/gtest.h>

#include <iostream>

TEST( BST, EMPTY_TEST ) {
    algorithm::bst<int> input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
    ASSERT_EQ( input.begin(), input.end() );
}

TEST( BST, INSERT_ONE_ELEMENT ) {
    algorithm::bst<int> input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
    input.insert( 1 );
}

TEST( BST, INSERT_FIVE_ELEMENT ) {
    algorithm::bst<int> input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
    input.insert( 3 );
    input.insert( 2 );
    input.insert( 5 );
    input.insert( 4 );
    input.insert( 1 );

    ASSERT_EQ( 1, *input.begin() );
    ASSERT_EQ( 5, input.size() );

    auto it = input.begin();
    for ( auto val : {1, 2, 3, 4, 5} ) {
        ASSERT_EQ( val, *it++ );
    }
}

TEST( BST, FOR_EACH_TEST ) {
    algorithm::bst<int> input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
    input.insert( 3 );
    input.insert( 2 );
    input.insert( 5 );
    input.insert( 4 );
    input.insert( 1 );

    ASSERT_EQ( 1, *input.begin() );
    ASSERT_EQ( 5, input.size() );
    std::vector<int> output = {1, 2, 3, 4, 5};
    auto output_iter        = output.begin();
    for ( auto& in : input ) {
        ASSERT_EQ( *output_iter++, in );
    }
}

TEST( BST, LVALUE_REF_TEST ) {
    algorithm::bst<int> input;
    std::vector<int> input_ref = {3, 2, 5, 4, 1};

    for ( auto& in : input_ref ) {
        input.insert( in );
    }

    ASSERT_EQ( 1, *input.begin() );
    ASSERT_EQ( 5, input.size() );
    std::vector<int> output = {1, 2, 3, 4, 5};
    auto output_iter        = output.begin();
    for ( auto& in : input ) {
        ASSERT_EQ( *output_iter++, in );
    }
}