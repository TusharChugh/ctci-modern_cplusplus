#include <trees_graphs/build_order.h>
#include <gtest/gtest.h>

TEST( BUILD_ORDER, DEMO ) {
    std::vector<char> projects = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::unordered_multimap<char, char> dependency_pairs = {
        {'d', 'a'}, {'b', 'f'}, {'d', 'b'}, {'a', 'f'}, {'c', 'd'}};
    std::vector<char> expected_output = {'f', 'a', 'b', 'd', 'c', 'e'};

    ASSERT_EQ( expected_output, algorithm::build_order( projects, dependency_pairs ) );
}

TEST( BUILD_ORDER, CYCLIC_TEST ) {
    std::vector<char> projects = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::unordered_multimap<char, char> dependency_pairs = {{'d', 'a'}, {'b', 'f'}, {'d', 'b'},
                                                            {'a', 'f'}, {'c', 'd'}, {'a', 'd'}};

    ASSERT_ANY_THROW( algorithm::build_order( projects, dependency_pairs ) );
}

TEST( BUILD_ORDER, EMPTY_TEST ) {
    std::vector<char> projects;
    std::unordered_multimap<char, char> dependency_pairs;
    std::vector<char> expected_output;

    ASSERT_EQ( expected_output, algorithm::build_order( projects, dependency_pairs ) );
}