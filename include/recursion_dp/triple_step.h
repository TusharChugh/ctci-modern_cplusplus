/**
 * @brief Triple Step
 * A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at
 * a time. Implement a method to count how many possible ways the child can run up the stairs
 *
 * @file triple_step.h
 * @author Tushar Chugh
 */

#pragma once

#include <vector>

namespace algorithm {

long long int triple_step( int n, std::vector<long long int>& mem );

long long int triple_step( int n ) {
    std::vector<long long int> mem( n + 1 );
    return triple_step( n, mem );
}

long long int triple_step( int n, std::vector<long long int>& mem ) {
    if ( n < 0 ) return 0;
    if ( n == 0 || n == 1 ) return 1;

    if ( mem.at( n ) == 0 )
        mem.at( n ) =
            triple_step( n - 1, mem ) + triple_step( n - 2, mem ) + triple_step( n - 3, mem );
    return mem.at( n );
}
} // namespace algorithm