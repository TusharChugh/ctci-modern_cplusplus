/**
 * @brief Conversion
 * Write a function to determine the number of bits you would need to flip to convert integer A to
 * integer B.
 *
 * @file conversion_flip.h
 * @author Tushar Chugh
 */

namespace algorithm {
/**
 * @brief  Determines the number of bits you would need to flip to convert input1 to input2
 * Notes:
 * Straight forward solution, counting bitwise. We can have better performace than this
 * @param input1 first number
 * @param input2 second number
 * @return unsigned int number of unique bits
 */
unsigned int flips_required_naive( int input1, int input2 ) {
    unsigned int count = 0;
    while ( input1 != 0 || input2 != 0 ) {
        if ( ( input1 & 1 ) ^ ( input2 & 1 ) ) ++count;
        input1 >>= 1;
        input2 >>= 1;
    }
    return count;
}

/**
 * @brief  Determines the number of bits you would need to flip to convert input1 to input2
 * Notes:
 * 1. xor for the numbers to get unique bits at once and then check the least significant bits
 * @param input1 first number
 * @param input2 second number
 * @return unsigned int number of unique bits
 */
unsigned int flips_required_shift( int input1, int input2 ) {
    unsigned int count = 0;
    for ( auto unique_bits = input1 ^ input2; unique_bits != 0; unique_bits >>= 1 ) {
        count += unique_bits & 1;
    }
    return count;
}

/**
 * @brief  Determines the number of bits you would need to flip to convert input1 to input2
 * Notes:
 * 1. more optimized than naive and shift approach
 * 2. continously flip the least significant bit and count how long it take to reach zero
 * 3. unique_bits & ( unique_bits - 1 ) clear the least significant bits
 * @param input1 first number
 * @param input2 second number
 * @return unsigned int number of unique bits
 */
unsigned int flips_required_trick( int input1, int input2 ) {
    unsigned int count = 0;
    for ( auto unique_bits = input1 ^ input2; unique_bits != 0;
          unique_bits      = unique_bits & ( unique_bits - 1 ) ) {
        ++count;
    }
    return count;
}

} // namespace algorithm