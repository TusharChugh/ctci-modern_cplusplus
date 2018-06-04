#include "include/recursion_dp/permutation_without_dups.h"
#include <gtest/gtest.h>

#include <unordered_set>

TEST( PERMS_WITHOUT_DUPS, EMPTY_INPUT ) {
    auto output = algorithm::perms_no_dups( "" );
    ASSERT_EQ( "", outut.front() );
    ASSERT_EQ( 1, output.size() );
}

TEST( PERMS_WITHOUT_DUPS, ONE_LETTERS ) {
    std::unordered_set<std::string> expected_output = {"a"};
    auto output                                     = algorithm::perms_no_dups( "a" );
    std::unordered_set<std::string> output_set;
    for ( const auto& word : output ) {
        output_set.insert( word );
    }
    ASSERT_EQ( expected_output, output_set );
}

TEST( PERMS_WITHOUT_DUPS, TWO_LETTERS ) {
    std::unordered_set<std::string> expected_output = {"ab", "ba"};
    auto output                                     = algorithm::perms_no_dups( "ab" );
    std::unordered_set<std::string> output_set;
    for ( const auto& word : output ) {
        output_set.insert( word );
    }
    ASSERT_EQ( expected_output, output_set );
}

TEST( PERMS_WITHOUT_DUPS, THREE_LETTERS ) {
    std::unordered_set<std::string> expected_output = {"abc", "acb", "bac", "bca", "cab", "cba"};
    auto output                                     = algorithm::perms_no_dups( "abc" );
    std::unordered_set<std::string> output_set;
    for ( const auto& word : output ) {
        output_set.insert( word );
    }
    ASSERT_EQ( expected_output, output_set );
}