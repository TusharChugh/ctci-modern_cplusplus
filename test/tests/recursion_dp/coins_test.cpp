#include <recursion_dp/coins.h>
#include <gtest/gtest.h>

TEST( COINS, THREE_COINS_RECURSIVE ) {
    std::vector<int> coins = {1, 2, 3};
    ASSERT_EQ( 4, algorithm::make_change_recursive( coins, 4 ) );
}

TEST( COINS, FIVE_COINS_RECURSIVE ) {
    std::vector<int> coins = {1, 2, 3, 4, 5};
    ASSERT_EQ( 7, algorithm::make_change_dp( coins, 5 ) );
}

TEST( COINS, THREE_COINS_DP ) {
    std::vector<int> coins = {1, 2, 3};
    ASSERT_EQ( 4, algorithm::make_change_dp( coins, 4 ) );
}

TEST( COINS, FIVE_COINS_DP ) {
    std::vector<int> coins = {1, 2, 3, 4, 5};
    ASSERT_EQ( 7, algorithm::make_change_dp( coins, 5 ) );
}