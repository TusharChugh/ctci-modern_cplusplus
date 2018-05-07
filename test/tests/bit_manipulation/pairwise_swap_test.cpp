#include "include/bit_manipulation/pairwise_swap.h"
#include <gtest/gtest.h>
#include <limits.h>

TEST( PAIRWISE_SWAP, ALTERNATIVE_BITS ) {
    ASSERT_EQ( 0xaaaaaaaa, algorithm::pairwise_swap( 0x55555555 ) );
    ASSERT_EQ( 0x55555555, algorithm::pairwise_swap( 0xaaaaaaaa ) );
}

TEST( PAIRWISE_SWAP, ZERO ) {
    ASSERT_EQ( 0, algorithm::pairwise_swap( 0 ) );
}

TEST( PAIRWISE_SWAP, MAX_MIN ) {
    ASSERT_EQ( -1, algorithm::pairwise_swap( -1 ) );
    ASSERT_EQ( 1 << 30, algorithm::pairwise_swap( INT_MIN ) );
    ASSERT_EQ( 0xbfffffff, algorithm::pairwise_swap( INT_MAX ) );
}