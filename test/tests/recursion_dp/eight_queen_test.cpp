#include <recursion_dp/eight_queen.h>
#include <gtest/gtest.h>

TEST( EIGHT_QUEEN, FOUR_CELLS ) {
    std::vector<std::vector<size_t>> expected_output = {{1, 3, 0, 2}, {2, 0, 3, 1}};
    ASSERT_EQ( expected_output, algorithm::place_queens( 4 ) );
}