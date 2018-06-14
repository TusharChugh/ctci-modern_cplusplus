#include "include/recursion_dp/stack_boxes.h"
#include <gtest/gtest.h>

using algorithm::Box;

TEST( STACK_BOXES, EMPTY_BOXES ) {
    std::vector<Box> boxes;
    ASSERT_EQ( 0, algorithm::tallest_stack( boxes ) );
}

TEST( STACK_BOXES, ONE_BOX ) {
    std::vector<Box> boxes = {Box{3, 3, 3}};
    ASSERT_EQ( 3, algorithm::tallest_stack( boxes ) );
}

TEST( STACK_BOXES, ONE_BOX_UNEQUAL_LENGTH ) {
    std::vector<Box> boxes = {Box{3, 1, 2}};
    ASSERT_EQ( 2, algorithm::tallest_stack( boxes ) );
}

TEST( STACK_BOXES, TWO_UNSTACKABLE_SAME_SIZE ) {
    std::vector<Box> boxes = {Box{2, 2, 2}, Box{2, 2, 2}};
    ASSERT_EQ( 2, algorithm::tallest_stack( boxes ) );
}

TEST( STACK_BOXES, THREE_SORTED_BOXES ) {
    std::vector<Box> boxes = {Box{1, 1, 1}, Box{2, 2, 2}, Box{3, 3, 3}};
    ASSERT_EQ( 6, algorithm::tallest_stack( boxes ) );
}

TEST( STACK_BOXES, THREE_REVERSE_SORTED_BOXES ) {
    std::vector<Box> boxes = {Box{3, 3, 3}, Box{2, 2, 2}, Box{1, 1, 1}};
    ASSERT_EQ( 6, algorithm::tallest_stack( boxes ) );
}

TEST( STACK_BOXES, THREE_UNSTACKABLE ) {
    std::vector<Box> boxes = {Box{4, 2, 1}, Box{2, 2, 2}, Box{3, 2, 2}};
    ASSERT_EQ( 2, algorithm::tallest_stack( boxes ) );
}

TEST( STACK_BOXES, TWO_STACKABLE_OFF_THREE ) {
    std::vector<Box> boxes = {Box{4, 2, 1}, Box{5, 5, 5}, Box{3, 2, 2}};
    ASSERT_EQ( 7, algorithm::tallest_stack( boxes ) );
}