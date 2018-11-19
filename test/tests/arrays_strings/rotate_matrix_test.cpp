#include <arrays_strings/rotate_matrix.h>
#include <gtest/gtest.h>

using algorithm::rotate_matrix;
using algorithm::rotate_matrix2;

TEST( ROTATE_MATRIX, THREE_THREE ) {
    algorithm::image_type input  = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    algorithm::image_type output = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    rotate_matrix( input );
    ASSERT_EQ( output, input );
}

TEST( ROTATE_MATRIX, ONE_ONE ) {
    algorithm::image_type input  = {{1}};
    algorithm::image_type output = {{1}};
    rotate_matrix( input );
    ASSERT_EQ( output, input );
}

TEST( ROTATE_MATRIX, TWO_TWO ) {
    algorithm::image_type input  = {{1, 2}, {3, 4}};
    algorithm::image_type output = {{3, 1}, {4, 2}};
    rotate_matrix( input );
    ASSERT_EQ( output, input );
}

TEST( ROTATE_MATRIX, FOUR_FOUR ) {
    algorithm::image_type input  = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    algorithm::image_type output = {{13, 9, 5, 1}, {14, 10, 6, 2}, {15, 11, 7, 3}, {16, 12, 8, 4}};
    rotate_matrix( input );
    ASSERT_EQ( output, input );
}

TEST( ROTATE_MATRIX, EMPTY ) {
    algorithm::image_type input  = {};
    algorithm::image_type output = {};
    rotate_matrix( input );
    ASSERT_EQ( output, input );
}

TEST( ROTATE_MATRIX, EMPTY_TWOD ) {
    algorithm::image_type input = {{}};
    ASSERT_ANY_THROW( rotate_matrix( input ) );
}

TEST( ROTATE_MATRIX, SINGLE_ROW ) {
    algorithm::image_type input = {{1, 2, 3}};
    ASSERT_ANY_THROW( rotate_matrix( input ) );
}

TEST( ROTATE_MATRIX, UNEQUAL ) {
    algorithm::image_type input = {{1, 2, 3}, {3, 2, 1}};
    ASSERT_ANY_THROW( rotate_matrix( input ) );
}


//Jesh
TEST( ROTATE_MATRIX2, THREE_THREE ) {
    algorithm::image_type input  = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    algorithm::image_type output = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    rotate_matrix2( input );
    ASSERT_EQ( output, input );
}

TEST( ROTATE_MATRIX2, ONE_ONE ) {
    algorithm::image_type input  = {{1}};
    algorithm::image_type output = {{1}};
    rotate_matrix2( input );
    ASSERT_EQ( output, input );
}

TEST( ROTATE_MATRIX2, TWO_TWO ) {
    algorithm::image_type input  = {{1, 2}, {3, 4}};
    algorithm::image_type output = {{3, 1}, {4, 2}};
    rotate_matrix2( input );
    ASSERT_EQ( output, input );
}

TEST( ROTATE_MATRIX2, FOUR_FOUR ) {
    algorithm::image_type input  = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    algorithm::image_type output = {{13, 9, 5, 1}, {14, 10, 6, 2}, {15, 11, 7, 3}, {16, 12, 8, 4}};
    rotate_matrix2( input );
    ASSERT_EQ( output, input );
}

TEST( ROTATE_MATRIX2, EMPTY ) {
    algorithm::image_type input  = {};
    algorithm::image_type output = {};
    rotate_matrix2( input );
    ASSERT_EQ( output, input );
}

TEST( ROTATE_MATRIX2, EMPTY_TWOD ) {
    algorithm::image_type input = {{}};
    ASSERT_ANY_THROW( rotate_matrix2( input ) );
}

TEST( ROTATE_MATRIX2, SINGLE_ROW ) {
    algorithm::image_type input = {{1, 2, 3}};
    ASSERT_ANY_THROW( rotate_matrix2( input ) );
}

TEST( ROTATE_MATRIX2, UNEQUAL ) {
    algorithm::image_type input = {{1, 2, 3}, {3, 2, 1}};
    ASSERT_ANY_THROW( rotate_matrix2( input ) );
}
