#include "include/stacks_queues/sort_stack.h"
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

constexpr size_t NUM_RANDOM_ELEMENTS = 5;
constexpr size_t seed                = 31;

TEST( SORT_STACK, REVERSE_ELEMENTS ) {
    std::stack<int> input;

    for ( int i = 1; i <= 5; ++i )
        input.push( i );

    auto output = algorithm::sort_stack( input );
    ASSERT_EQ( output.size(), input.size() );

    for ( int i = 1; i <= 5; ++i ) {
        ASSERT_EQ( i, output.top() );
        output.pop();
    }
}

TEST( SORT_STACK, SORTED_ELEMENTS ) {
    std::stack<int> input;

    for ( int i = 5; i >= 1; --i )
        input.push( i );

    auto output = algorithm::sort_stack( input );

    ASSERT_EQ( output.size(), input.size() );

    for ( int i = 1; i <= 5; ++i ) {
        ASSERT_EQ( i, output.top() );
        output.pop();
    }
}

TEST( SORT_STACK, FIVE_RANDOM_ELEMENTS ) {
    std::vector<int> random_values( NUM_RANDOM_ELEMENTS );
    std::srand( seed );
    std::generate( random_values.begin(), random_values.end(), []() { return std::rand() % 100; } );

    std::stack<int> input;

    for ( const auto random_value : random_values )
        input.push( random_value );

    auto output = algorithm::sort_stack( input );
    std::sort( random_values.begin(), random_values.end() );

    for ( const auto random_value : random_values ) {
        ASSERT_EQ( random_value, output.top() );
        output.pop();
    }
}

TEST( SORT_STACK, THOUSAND_RANDOM_ELEMENTS ) {
    std::vector<int> random_values( 1000 );
    std::srand( seed );
    std::generate( random_values.begin(), random_values.end(), []() { return std::rand(); } );

    std::stack<int> input;

    for ( const auto random_value : random_values )
        input.push( random_value );

    auto output = algorithm::sort_stack( input );
    std::sort( random_values.begin(), random_values.end() );

    for ( const auto random_value : random_values ) {
        ASSERT_EQ( random_value, output.top() );
        output.pop();
    }
}