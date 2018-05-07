/**
 * @brief Pairwise Swap
 * Write a program to swap odd and even bits in an integer with as few instructions as possible
 * (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).
 *
 * @file pairwise_swap.h
 * @author Tushar Chugh
 */

namespace algorithm {
/**
 * @brief swaps even and odd bits
 * Notes:
 * 1. Create masks for even and odd bits
 * 2. After applying mask 0xaaaaaaaa  inputs needs to be right shifted. using static_cast for
 * handling signed integers
 * @param input input number
 * @return int output number with swapped even and odd bits
 */
int pairwise_swap( int input ) {
    return ( ( static_cast<unsigned int>( input & 0xaaaaaaaa ) >> 1 ) |
             ( ( input & 0x55555555 ) << 1 ) );
}
} // namespace algorithm