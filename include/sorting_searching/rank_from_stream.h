/**
Rank from Stream: Imagine you are reading in a stream of integers. Periodically, you wish
to be able to look up the rank of a number x (the number of values less than or equal to x).
Implement the data structures and algorithms to support these operations. That is, implement
the method track(int x), which is called when each number is generated, and the method
getRankOfNumber(int x), which returns the number of values less than or equal to x (not
including x itself).
EXAMPLE
Stream (in order of appearance) : 5, 1, 4, 4, 5, 9, 7, 13, 3
getRankOfNumber(1) 0
getRankOfNumber(3) 1
getRankOfNumber(4) 3
**/

#pragma once

#include "include/trees_graphs/bst.h"

namespace algorithm {
    /**
     * Track is log(N) and get rank is N. Using existing bst implementation
     */
    class rank_stream {
    public:
        rank_stream() = default;
        ~rank_stream() = default;

        void track(int num) {
            graph.insert(num);
        }

        int get_rank(int num) {
            auto target = graph.find(num);
            if(target == graph.end()) return -1;
            auto begin = graph.begin();
            int rank = 0;
            while(begin++ != target) ++rank;

            return rank;
        }

    private:
        algorithm::bst<int> graph;

    };
}