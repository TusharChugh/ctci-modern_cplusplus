#include <arrays_strings/zero_matrix.h>
#include <gtest/gtest.h>

TEST( ZERO_MATRIX, THREE_SQUARE_SPARSE ) {
    std::vector<std::vector<int>> input  = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    std::vector<std::vector<int>> output = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    algorithm::zero_matrix_spase( input );
    ASSERT_EQ( output, input );
}

TEST( ZERO_MATRIX, THREE_SQUARE_INPLACE ) {
    std::vector<std::vector<int>> input  = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    std::vector<std::vector<int>> output = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    algorithm::zero_matrix_inplace( input );
    ASSERT_EQ( output, input );
}