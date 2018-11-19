#include <linked_lists/forward_list.h>
#include <gtest/gtest.h>

using Forward_List = algorithm::Forward_List<int>;
using node_pointer = algorithm::Forward_List<int>::node_pointer;

TEST( FORWARD_LIST, EMPTY_LIST ) {
    Forward_List list;
    ASSERT_EQ( 0, list.size() );
}

TEST( FORWARD_LIST, ONE_ELEMENT ) {
    int a = 5;
    Forward_List list;
    auto first = list.push_front( a );
    ASSERT_EQ( 1, list.size() );
    ASSERT_EQ( 5, first->value_ );
}

TEST( FORWARD_LIST, TWO_ELEMENTS ) {
    int a = 5;
    int b = 6;
    Forward_List list;
    auto first = list.push_front( a );
    ASSERT_EQ( 1, list.size() );
    ASSERT_EQ( 5, first->value_ );

    auto second = list.push_front( b );
    ASSERT_EQ( 2, list.size() );
    ASSERT_EQ( 6, second->value_ );
}

TEST( FORWARD_LIST, BEGIN_ELEMENTS ) {
    int a = 5;
    int b = 6;
    Forward_List list;
    auto first = list.push_front( a );
    ASSERT_EQ( 1, list.size() );
    ASSERT_EQ( 5, list.front()->value_ );

    auto second = list.push_front( b );
    ASSERT_EQ( 2, list.size() );
    ASSERT_EQ( 6, list.front()->value_ );
}