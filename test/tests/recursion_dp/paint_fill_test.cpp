#include <recursion_dp/paint_fill.h>
#include <gtest/gtest.h>

TEST( PAIN_FILL, SQUARE_MIDDLE_EVEN_GRID ) {
    std::vector<std::vector<unsigned short>> image = {
        {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    std::vector<std::vector<unsigned short>> expected_output = {
        {0, 0, 0, 0}, {0, 10, 10, 0}, {0, 10, 10, 0}, {0, 0, 0, 0}};
    auto copy_1( image );
    auto copy_2( image );
    auto copy_3( image );
    auto copy_4( image );
    algorithm::fill_paint( copy_1, 1, 1, 10 );
    algorithm::fill_paint( copy_2, 1, 2, 10 );
    algorithm::fill_paint( copy_3, 2, 1, 10 );
    algorithm::fill_paint( copy_4, 2, 2, 10 );
    ASSERT_EQ( expected_output, copy_1 );
    ASSERT_EQ( expected_output, copy_2 );
    ASSERT_EQ( expected_output, copy_3 );
    ASSERT_EQ( expected_output, copy_4 );
}

TEST( PAIN_FILL, SAME_COLOR ) {
    std::vector<std::vector<unsigned short>> image = {
        {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    std::vector<std::vector<unsigned short>> expected_output = {
        {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    auto copy_1( image );
    auto copy_2( image );
    auto copy_3( image );
    auto copy_4( image );
    algorithm::fill_paint( copy_1, 1, 1, 1 );
    algorithm::fill_paint( copy_2, 1, 2, 1 );
    algorithm::fill_paint( copy_3, 2, 1, 1 );
    algorithm::fill_paint( copy_4, 2, 2, 1 );
    ASSERT_EQ( expected_output, copy_1 );
    ASSERT_EQ( expected_output, copy_2 );
    ASSERT_EQ( expected_output, copy_3 );
    ASSERT_EQ( expected_output, copy_4 );
}

TEST( PAIN_FILL, COLOR_FULL ) {
    std::vector<std::vector<unsigned short>> image = {
        {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    std::vector<std::vector<unsigned short>> expected_output = {
        {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    auto copy_1( image );
    auto copy_2( image );
    auto copy_3( image );
    auto copy_4( image );
    algorithm::fill_paint( copy_1, 1, 1, 1 );
    algorithm::fill_paint( copy_2, 1, 2, 1 );
    algorithm::fill_paint( copy_3, 2, 1, 1 );
    algorithm::fill_paint( copy_4, 2, 2, 1 );
    ASSERT_EQ( expected_output, copy_1 );
    ASSERT_EQ( expected_output, copy_2 );
    ASSERT_EQ( expected_output, copy_3 );
    ASSERT_EQ( expected_output, copy_4 );
}