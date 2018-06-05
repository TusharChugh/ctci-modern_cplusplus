/**
 * @brief solving 9x9 suduko game
 *
 * @file sudoku_solver.h
 * @author Tushar Chugh
 */

#pragma once

#include <iostream>
#include <vector>

namespace algorithm {

// This is to check if the number is in the small box
bool isInBox( std::vector<std::vector<char>>& board, int start_row, int start_col, char num ) {
    for ( size_t row = 0; row < 3; ++row ) {
        for ( size_t col = 0; col < 3; ++col ) {
            if ( board[start_row + row][start_col + col] == num ) return true;
        }
    }
    return false;
}

// This is to check if the number is in the row
bool isInRow( std::vector<std::vector<char>>& board, int row, char num ) {
    for ( size_t col = 0; col < board.size(); ++col ) {
        if ( board[row][col] == num ) return true;
    }
    return false;
}

// This is to check if the number is in the column
bool isInCol( std::vector<std::vector<char>>& board, int col, char num ) {
    for ( size_t row = 0; row < board.size(); ++row ) {
        if ( board[row][col] == num ) return true;
    }
    return false;
}

bool isValidLocation( std::vector<std::vector<char>>& board, int row, int col, char num ) {
    if ( isInCol( board, col, num ) ) return false;
    if ( isInRow( board, row, num ) ) return false;
    if ( isInBox( board, row - row % 3, col - col % 3, num ) ) return false;
    return true;
}

std::pair<int, int> getEmptySpot( const std::vector<std::vector<char>>& board ) {
    for ( size_t row = 0; row < board.size(); ++row ) {
        for ( size_t col = 0; col < board.size(); ++col ) {
            if ( board[row][col] == '.' ) return std::make_pair<char, char>( row, col );
        }
    }
    return std::make_pair<char, char>( -1, -1 );
}

bool sudokuSolve( std::vector<std::vector<char>>& board ) {
    auto empty_spot = getEmptySpot( board );
    if ( empty_spot.first == -1 || empty_spot.second == -1 ) return true;
    for ( char val = '1'; val <= '9'; val++ ) {
        int row = empty_spot.first;
        int col = empty_spot.second;

        if ( isValidLocation( board, empty_spot.first, empty_spot.second, val ) ) {
            board[row][col] = val;
            if ( sudokuSolve( board ) ) return true;
            board[row][col] = '.';
        }
    }
    return false;
}
} // namespace algorithm
