#include <gtest/gtest.h>
#include "include/stacks_queues/three_one.h"

TEST(THREE_ONE, THREE_SIZE_TWO_STACKS) {
    algorithm::MultiStack<int> input(6, 2);
    input.push(0, 1);
    ASSERT_EQ(1, input.top(0));
    input.push(0, 2);
    ASSERT_EQ(2, input.top(0));
    //ASSERT_EQ(2, input.size(0));

    input.push(1, 3);
//    ASSERT_EQ(3, input.top(1));
//    input.push(1, 4);
//    ASSERT_EQ(4, input.top(1));
//
//    input.push(2, 4);
//    ASSERT_EQ(4, input.top(2));
//    input.push(2, 5);
//    ASSERT_EQ(5, input.top(2));
}