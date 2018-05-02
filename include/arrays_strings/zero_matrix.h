/**
 * @brief Zero Matrix
 * Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are
 * set to O.
 *
 * @file zero_matrix.h
 * @author Tushar Chugh
 */

#pragma once

#include <vector>

namespace algorithm {
// Works well for sparse matrices because of cache hits
void zero_matrix_spase( std::vector<std::vector<int>>& input ) {
    using size_t = typename std::vector<int>::size_type;
    if ( input.empty() ) return;
    const size_t num_rows = input.size();
    const size_t num_cols = input.at( 0 ).size();

    std::vector<bool> zeros_rows( input.size() );
    std::vector<bool> zero_cols( input.size() );

    // Store zeros indices
    for ( size_t row = 0; row < num_rows; ++row ) {
        for ( size_t col = 0; col < num_cols; ++col ) {
            if ( input[row][col] == 0 ) {
                zeros_rows[row] = true;
                zero_cols[col]  = true;
            }
        }
    }

    // Making the values zeros
    for ( size_t row = 0; row < num_rows; ++row ) {
        for ( size_t col = 0; col < num_cols; ++col ) {
            if ( zero_cols[row] == true || zero_cols[col] == true ) input[row][col] = 0;
        }
    }
}

// inplace
void zero_matrix_inplace( std::vector<std::vector<int>>& input ) {
    using size_t = typename std::vector<int>::size_type;
    if ( input.empty() ) return;
    const size_t num_rows = input.size();
    const size_t num_cols = input.at( 0 ).size();

    // Store zeros indices
    for ( size_t row = 0; row < num_rows; ++row ) {
        for ( size_t col = 0; col < num_cols; ++col ) {
            if ( input[row][col] == 0 ) {
                input[0][col] = 0;
                input[row][0] = 0;
            }
        }
    }

    // Making the values zeros
    for ( size_t row = 0; row < num_rows; ++row ) {
        for ( size_t col = 0; col < num_cols; ++col ) {
            if ( input[row][0] == 0 || input[0][col] == 0 ) input[row][col] = 0;
        }
    }
}
} // namespace algorithm