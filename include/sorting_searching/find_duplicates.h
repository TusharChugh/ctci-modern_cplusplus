/**
 * Find Duplicates: You have an array with all the numbers from 1 to N, where N is at most 32,000. The
array may have duplicate entries and you do not know what N is. With only 4 kilobytes of memory
available, how would you print all duplicate elements in the array?
 */

#pragma once

#include <bitset>
#include <vector>
#include <unordered_set>

namespace algorithm {
    constexpr unsigned MAX_SIZE= 32000;
    /**
     * Assumes input are positive integers
     * @param input
     * @return
     */
    std::unordered_set<int> find_duplicates(std::vector<int> input) {
        std::bitset<MAX_SIZE> visited;
        std::unordered_set<int> duplicates;

        for(const auto& num: input) {
            if(visited[num - 1]) duplicates.insert(num);
            else visited[num - 1] = 1;
        }
        return duplicates;
    }
}