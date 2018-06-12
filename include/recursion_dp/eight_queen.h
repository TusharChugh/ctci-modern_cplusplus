/**
 * @brief Eight Queens
 * Write an algorithm to print all ways of arranging eight queens on an 8x8 chess board so that none
 * of them share the same row, column, or diagonal. In this case, "diagonal" means all diagonals,
 * not just the two that bisect the board.
 *
 * @file eight_queen.h
 * @author Tushar Chugh
 */

#pragma once

#include <cstddef>
#include <vector>

namespace algorithm {
bool is_valid( const std::vector<size_t>& rows, size_t row, size_t col ) {
    for ( size_t col_id = 0; col_id < col; ++col_id ) {
        auto row_id = rows[col_id];
        if ( row_id == row ) return false;

        size_t col_dist = ( col > col_id ) ? col - col_id : col_id - col;
        size_t row_dist = ( row > row_id ) ? row - row_id : row_id - row;

        if ( col_dist == row_dist ) return false;
    }
    return true;
}

void place_queens( size_t col, std::vector<size_t> rows,
                   std::vector<std::vector<size_t>>& result ) {
    if ( col == rows.size() ) {
        result.push_back( rows );
        return;
    }

    for ( size_t row = 0; row < rows.size(); ++row ) {
        if ( is_valid( rows, row, col ) ) {
            rows[col] = row;
            place_queens( col + 1, rows, result );
        }
    }
}

std::vector<std::vector<size_t>> place_queens( size_t board_size ) {
    std::vector<std::vector<size_t>> result;
    std::vector<size_t> rows( board_size );
    place_queens( 0, rows, result );
    return result;
}
} // namespace algorithm