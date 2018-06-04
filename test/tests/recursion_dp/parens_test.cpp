#include "include/recursion_dp/parens.h"
#include <gtest/gtest.h>
#include <unordered_set>

TEST( PARENS, TWO_COUNT ) {
    std::unordered_set<std::string> expected_output = {"()()", "(())"};
    auto output                                     = algorithm::generate_parens( 2 );
    std::unordered_set<std::string> output_set;
    for ( const auto& combination : output )
        output_set.insert( combination );
    ASSERT_EQ( expected_output, output_set );
}

TEST( PARENS, THREE_COUNT ) {
    std::unordered_set<std::string> expected_output = {"()()()", "((()))", "(())()", "()(())",
                                                       "(()())"};
    auto output                                     = algorithm::generate_parens( 3 );
    std::unordered_set<std::string> output_set;
    for ( const auto& combination : output )
        output_set.insert( combination );
    ASSERT_EQ( expected_output, output_set );
}