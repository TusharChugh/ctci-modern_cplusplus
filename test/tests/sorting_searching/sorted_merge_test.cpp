#include <gtest/gtest.h>
#include <sorting_searching/sorted_merge.h>

TEST(SORTED_MERGE, ALTERNATE_SEQUENCE) {
    std::vector<int> A = {1, 3, 5, 7, 0, 0, 0, 0};
    std::vector<int> B = {2, 4, 6, 8};

    std::vector<int> expected_output = {1, 2, 3, 4, 5, 6, 7, 8};
    algorithm::sorted_merge(A, B, 4);

    ASSERT_EQ(expected_output, A);
}


TEST(SORTED_MERGE, SAME_ELEMENTS) {
    std::vector<int> A = {1, 3, 5, 7, 0, 0, 0, 0};
    std::vector<int> B = {1, 3, 5, 7};

    std::vector<int> expected_output = {1, 1, 3, 3, 5, 5, 7, 7};
    algorithm::sorted_merge(A, B, 4);

    ASSERT_EQ(expected_output, A);
}