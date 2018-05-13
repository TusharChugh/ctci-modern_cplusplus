#include "include/trees_graphs/bst.h"
#include <gtest/gtest.h>

#include <iostream>

TEST( BST, EMPTY_TEST ) {
    algorithm::bst<int> input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
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
    std::cout << *it++ << " ";
    std::cout << *it++ << " ";
    std::cout << *it++ << " ";
    std::cout << *it++ << " ";
    std::cout << *it++ << " ";
    for ( auto in : input ) {
        std::cout << in << " ";
    }
    std::cout << std::endl;
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
    for ( auto in : input ) {
        std::cout << in << " ";
    }
    std::cout << std::endl;
}