/**
 * @brief Recursive Multiply
 * Write a recursive function to multiply two positive integers without using the * operator. You
 * can use addition, subtraction, and bit shifting, but you should minimize the number of those
 * operations.
 *
 * @file recursive_multiply.h
 * @author Tushar Chugh
 */

#pragma once

#include <vector>

namespace algorithm {
long long int recursive_multiply( int num, int times, std::vector<int>& mem ) {
    if ( times == 0 ) return 0;
    if ( times == 1 ) return num;

    int times_half = times >> 1;
    if ( mem.at( times - 1 ) == 0 ) {
        auto half_prod = recursive_multiply( num, times_half, mem );
        if ( times % 2 == 0 )
            return half_prod + half_prod;
        else
            return half_prod + half_prod + num;
    }
    return mem.at( times - 1 );
}

/**
 * @brief multiply num * times recursively
 * Less number of recursive calls if times is smaller so, doing this optimization in the code before
 * calling the recursive function
 * @param num input num
 * @param times to be multplies with
 * @return long long int result
 */
long long int recursive_multiply( int num, int times ) {
    if ( times < num ) {
        std::vector<int> mem( times );
        return recursive_multiply( num, times, mem );
    } else {
        std::vector<int> mem( num );
        return recursive_multiply( times, num, mem );
    }
}
} // namespace algorithm