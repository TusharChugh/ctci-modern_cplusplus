#include <sorting_searching/peaks_valleys.h>
#include <gtest/gtest.h>

TEST( PEAKS_VALLEYS, DEMO ) {
    std::vector<int> input           = {1, 4, 0, 8, 7, 9};
    std::vector<int> expected_output = {1, 0, 7, 4, 9, 8};
    algorithm::peaks_valleys_sort( input );
    ASSERT_EQ( expected_output, input );
}