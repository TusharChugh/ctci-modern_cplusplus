#include <stacks_queues/queue_stack.h>
#include <gtest/gtest.h>

TEST( QUEUE_STACK, SERIAL_PUSH_POP ) {
    algorithm::queue_stack<int> input;
    ASSERT_TRUE( input.empty() );

    input.push( 5 );
    input.push( 6 );
    input.push( 7 );

    ASSERT_EQ( 3, input.size() );
    ASSERT_EQ( 5, input.front() );

    input.pop();

    ASSERT_EQ( 2, input.size() );
    ASSERT_EQ( 6, input.front() );

    input.pop();

    ASSERT_EQ( 1, input.size() );
    ASSERT_EQ( 7, input.front() );

    input.pop();

    ASSERT_EQ( 0, input.size() );
    ASSERT_TRUE( input.empty() );
}

TEST( QUEUE_STACK, MULTIPLE_PUSH_POP ) {
    algorithm::queue_stack<int> input;
    ASSERT_TRUE( input.empty() );

    input.push( 5 );
    input.push( 6 );
    input.push( 7 );

    ASSERT_EQ( 3, input.size() );
    ASSERT_EQ( 5, input.front() );

    input.pop();

    ASSERT_EQ( 2, input.size() );
    ASSERT_EQ( 6, input.front() );

    input.push( 1 );
    input.push( 2 );

    ASSERT_EQ( 4, input.size() );
    ASSERT_EQ( 6, input.front() );

    input.pop();

    ASSERT_EQ( 3, input.size() );
    ASSERT_EQ( 7, input.front() );

    input.pop();

    ASSERT_EQ( 2, input.size() );
    ASSERT_EQ( 1, input.front() );

    input.pop();

    ASSERT_EQ( 1, input.size() );
    ASSERT_EQ( 2, input.front() );

    input.pop();

    ASSERT_EQ( 0, input.size() );
    ASSERT_TRUE( input.empty() );
}