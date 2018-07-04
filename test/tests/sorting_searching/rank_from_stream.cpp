#include <gtest/gtest.h>
#include "include/sorting_searching/rank_from_stream.h"

TEST(RANK_FROM_STREAM, ) {
    algorithm::rank_stream rank_graph;
    for(auto num: {1, 4, 5, 9, 7, 13, 3}) {
        rank_graph.track(num);
    }
    ASSERT_EQ(0, rank_graph.get_rank(1));
    ASSERT_EQ(1, rank_graph.get_rank(3));
    ASSERT_EQ(2, rank_graph.get_rank(4));
    ASSERT_EQ(5, rank_graph.get_rank(9));

    ASSERT_EQ(-1, rank_graph.get_rank(2));
}