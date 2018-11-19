#include <stacks_queues/stack_plates.h>
#include <gtest/gtest.h>

TEST( STACK_PLATES, DEMO_TEST ) {
    algorithm::set_stacks<int> stacks( 3 );

    ASSERT_TRUE( stacks.empty() );

    for ( int i = 1; i <= 15; ++i ) {
        stacks.push( i );
        ASSERT_EQ( i, stacks.top() );
        ASSERT_EQ( i, stacks.size() );
        ASSERT_FALSE( stacks.empty() );
    }

    for ( int i = 15; i > 0; --i ) {
        ASSERT_EQ( i, stacks.top() );
        ASSERT_EQ( i, stacks.size() );
        ASSERT_FALSE( stacks.empty() );
        stacks.pop();
    }
    ASSERT_TRUE( stacks.empty() );
}