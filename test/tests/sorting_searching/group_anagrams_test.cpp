#include <sorting_searching/group_anagrams.h>
#include <gtest/gtest.h>

TEST( GROUP_ANAGRAMS, TWO_ANAGRAMS ) {
    std::vector<std::string> input = {"hello", "hell", "elloh"};
    algorithm::group_anagrams( input );
    ASSERT_EQ( 1, std::abs(std::find(input.begin(), input.end(), "hello") - std::find(input.begin(), input.end(), "elloh")));
}

TEST( GROUP_ANAGRAMS, TWO_PAIRS_ANAGRAMS_SEVEN_WORDS ) {
    std::vector<std::string> input = {"abccdde", "abc", "abccd",  "addccbe",
                                      "accdb",   "abd", "aebcdcd"};
    algorithm::group_anagrams( input );

    auto index1 = std::find(input.begin(), input.end(), "aebcdcd");
    auto index2 = std::find(input.begin(), input.end(), "addccbe");
    auto index3 = std::find(input.begin(), input.end(), "abccdde");


    ASSERT_EQ( 2, std::max({index1, index2, index3}) - std::min({index1, index2, index3}));

    ASSERT_EQ( 1, std::abs(std::find(input.begin(), input.end(), "accdb") - std::find(input.begin(), input.end(), "abccd")));
}