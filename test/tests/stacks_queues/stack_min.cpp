#include "include/stacks_queues/stack_min.h"
#include <gtest/gtest.h>

TEST( STACK_MIN, FIVE_ELEMENTS ) {
    algorithm::stack_min min_stack;
    std::vector<int> input       = {5, 6, 4, 7, 2, 2, 8, 1};
    std::vector<int> output_push = {5, 5, 4, 4, 2, 2, 2, 1};
    auto output_iter             = output_push.begin();
    for ( auto value : {5, 6, 4, 7, 2, 2, 8, 1} ) {
        min_stack.push( value );
        ASSERT_EQ( *output_iter++, min_stack.min() );
    }

    while ( !min_stack.empty() ) {
        ASSERT_EQ( *( --output_iter ), min_stack.min() );
        min_stack.pop();
    }
}