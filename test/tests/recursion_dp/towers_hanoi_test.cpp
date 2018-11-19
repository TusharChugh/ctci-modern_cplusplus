#include <recursion_dp/towers_hanoi.h>
#include <gtest/gtest.h>

#include <iostream>

TEST( TOWERS_HANOI, THREE_DISKS ) {
    algorithm::Tower input = {3, 2, 1};
    algorithm::Tower buffer;
    algorithm::Tower destination;
    input.move_disks( input.size(), destination, buffer );
    algorithm::Tower expected_output = {3, 2, 1};
    ASSERT_TRUE( input.empty() );
    ASSERT_TRUE( buffer.empty() );
    ASSERT_EQ( expected_output, destination );
}

TEST( TOWERS_HANOI, FIVE_DISKS ) {
    algorithm::Tower input = {5, 4, 3, 2, 1};
    algorithm::Tower buffer;
    algorithm::Tower destination;
    input.move_disks( input.size(), destination, buffer );
    algorithm::Tower expected_output = {5, 4, 3, 2, 1};
    ASSERT_TRUE( input.empty() );
    ASSERT_TRUE( buffer.empty() );
    ASSERT_EQ( expected_output, destination );
}

TEST( TOWERS_HANOI, ONE_DISKS ) {
    algorithm::Tower input = {5};
    algorithm::Tower buffer;
    algorithm::Tower destination;
    input.move_disks( input.size(), destination, buffer );
    algorithm::Tower expected_output = {5};
    ASSERT_TRUE( input.empty() );
    ASSERT_TRUE( buffer.empty() );
    ASSERT_EQ( expected_output, destination );
}

TEST( TOWERS_HANOI, EMPTY ) {
    algorithm::Tower input;
    algorithm::Tower buffer;
    algorithm::Tower destination;
    input.move_disks( input.size(), destination, buffer );
    algorithm::Tower expected_output;
    ASSERT_TRUE( input.empty() );
    ASSERT_TRUE( buffer.empty() );
    ASSERT_EQ( expected_output, destination );
}