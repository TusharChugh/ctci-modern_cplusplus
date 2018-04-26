#include <gtest/gtest.h>
#include "include/linked_lists/palindrome_list.h"

using algorithm::is_palindrome_reverse;
using algorithm::is_palindrome_stack;

TEST( PALINDROME_LIST, REVERSE_METHOD_LETTERS ) {
    std::forward_list<char> input = {'a', 'b', 'c', 'c', 'b', 'a'};
    ASSERT_TRUE( is_palindrome_reverse( input ) );
}

TEST( PALINDROME_LIST, STACK_MENTHOD_LETTERS ) {
    std::forward_list<char> input = {'a', 'b', 'c', 'c', 'b', 'a'};
    ASSERT_TRUE( is_palindrome_stack( input ) );
}