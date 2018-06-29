#include "include/sorting_searching/group_anagrams.h"
#include <gtest/gtest.h>

// NOTE: The tests are hardcode and are ordered depedent. It shouldn't be the case

TEST( GROUP_ANAGRAMS, TWO_ANAGRAMS ) {
    std::vector<std::string> input = {"hello", "hell", "elloh"};
    algorithm::group_anagrams( input );
    std::vector<std::string> expected_output = {"hell", "elloh", "hello"};
    ASSERT_EQ( expected_output, input );
}

TEST( GROUP_ANAGRAMS, TWO_PAIRS_ANAGRAMS_SEVEN_WORDS ) {
    std::vector<std::string> input = {"abccdde", "abc", "abccd",  "addccbe",
                                      "accdb",   "abd", "aebcdcd"};
    algorithm::group_anagrams( input );
    std::vector<std::string> expected_output = {"abd",     "abc",   "aebcdcd", "addccbe",
                                                "abccdde", "accdb", "abccd"};
    ASSERT_EQ( expected_output, input );
}