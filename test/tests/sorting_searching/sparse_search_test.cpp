#include <sorting_searching/sparse_search.h>
#include <gtest/gtest.h>

TEST( SPARSE_SEARCH, DEMO ) {
    std::vector<std::string> input = {"at",  "", "", "",    "ball", "", "",
                                      "car", "", "", "dad", "",     ""};
    ASSERT_EQ( 4, algorithm::sparse_search( input, "ball" ) );
}