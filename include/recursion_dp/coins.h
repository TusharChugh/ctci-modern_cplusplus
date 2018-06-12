/**
 * @brief Coins
 * Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents),  and
 * pennies (1 cent), write code to calculate the number of ways of representing n cents.
 *
 * @file coins.h
 * @author Tushar Chugh
 */

#pragma once

#include <vector>

namespace algorithm {
int make_change( const std::vector<int>& coins, int sum, int index ) {
    if ( sum == 0 ) return 1;
    if ( sum < 0 ) return 0;
    if ( index <= 0 ) return 0;

    return make_change( coins, sum, index - 1 ) +
           make_change( coins, sum - coins[index - 1], index );
}

int make_change_recursive( const std::vector<int>& coins, int sum ) {
    return make_change( coins, sum, coins.size() );
}

int make_change_dp( const std::vector<int>& coins, unsigned sum ) {
    std::vector<std::vector<int>> table( coins.size() + 1, std::vector<int>( sum + 1 ) );
    table[0][0] = 1;
    for ( auto row = 1; row <= coins.size(); ++row ) {
        for ( auto col = 0; col <= sum; ++col ) {
            auto sum_excluding = ( row - 1 >= 0 ) ? table[row - 1][col] : 0;
            auto sum_including =
                ( col - coins[row - 1] >= 0 ) ? table[row][col - coins[row - 1]] : 0;
            table[row][col] = sum_excluding + sum_including;
        }
    }
    return table[coins.size()][sum];
}
} // namespace algorithm