#include <gtest/gtest.h>
#include <set>
#include "include/recursion_dp/sudoku_solver.h"

void printBoard( std::vector<std::vector<char>>& board ) {
    for ( auto row : board ) {
        for ( auto val : row ) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

TEST( SUDOKU, SUDOKU_SOLVER_TEST ) {
    std::vector<std::vector<char>> input{{'.', '.', '.', '7', '.', '.', '3', '.', '1'},
                                         {'3', '.', '.', '9', '.', '.', '.', '.', '.'},
                                         {'.', '4', '.', '3', '1', '.', '2', '.', '.'},
                                         {'.', '6', '.', '4', '.', '.', '5', '.', '.'},
                                         {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                         {'.', '.', '1', '.', '.', '8', '.', '4', '.'},
                                         {'.', '.', '6', '.', '2', '1', '.', '5', '.'},
                                         {'.', '.', '.', '.', '.', '9', '.', '.', '8'},
                                         {'8', '.', '5', '.', '.', '4', '.', '.', '.'}};

    std::vector<std::vector<char>> output{{'5', '8', '9', '7', '4', '2', '3', '6', '1'},
                                          {'3', '1', '2', '9', '8', '6', '4', '7', '5'},
                                          {'6', '4', '7', '3', '1', '5', '2', '8', '9'},
                                          {'2', '6', '8', '4', '9', '3', '5', '1', '7'},
                                          {'4', '9', '3', '1', '5', '7', '8', '2', '6'},
                                          {'7', '5', '1', '2', '6', '8', '9', '4', '3'},
                                          {'9', '3', '6', '8', '2', '1', '7', '5', '4'},
                                          {'1', '2', '4', '5', '7', '9', '6', '3', '8'},
                                          {'8', '7', '5', '6', '3', '4', '1', '9', '2'}};
    //    printBoard(input);
    algorithm::sudokuSolve( input );
    //    std::cout<<"Result"<<std::endl;
    //    printBoard(input);
    for ( size_t i = 0; i < input.size(); ++i ) {
        for ( size_t j = 0; j < input[0].size(); ++j ) {
            ASSERT_EQ( input[i][j], output[i][j] );
        }
    }
}
