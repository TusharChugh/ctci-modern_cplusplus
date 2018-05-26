#include "include/linked_lists/intersection.h"
#include <gtest/gtest.h>

using algorithm::find_intersection;
using algorithm::Forward_List_Node;
using algorithm::intersection_hash;

TEST( INTERSECTION_LIST, SAME_LIST_HASH ) {
    auto first = std::make_shared<Forward_List_Node<int>>( 0 );
    auto a     = std::make_shared<Forward_List_Node<int>>( 1 );
    auto b     = std::make_shared<Forward_List_Node<int>>( 2 );
    auto c     = std::make_shared<Forward_List_Node<int>>( 3 );

    first->next_ = a;
    a->next_     = b;
    b->next_     = c;

    auto result = intersection_hash( first, first );
    ASSERT_EQ( first, result );
}

TEST( INTERSECTION_LIST, CYCLE_AFTER_ONE_HASH ) {
    auto first = std::make_shared<Forward_List_Node<int>>( 0 );
    auto a     = std::make_shared<Forward_List_Node<int>>( 1 );
    auto b     = std::make_shared<Forward_List_Node<int>>( 2 );
    auto c     = std::make_shared<Forward_List_Node<int>>( 3 );

    auto second = std::make_shared<Forward_List_Node<int>>( 0 );

    first->next_ = a;
    a->next_     = b;
    b->next_     = c;

    second->next_ = a;

    auto result = intersection_hash( first, second );
    ASSERT_EQ( a, result );
}

TEST( INTERSECTION_LIST, CYCLE_AFTER_TWO_HASH ) {
    auto first  = std::make_shared<Forward_List_Node<int>>( 0 );
    auto first1 = std::make_shared<Forward_List_Node<int>>( 10 );
    auto a      = std::make_shared<Forward_List_Node<int>>( 1 );
    auto b      = std::make_shared<Forward_List_Node<int>>( 2 );
    auto c      = std::make_shared<Forward_List_Node<int>>( 3 );

    auto second  = std::make_shared<Forward_List_Node<int>>( 0 );
    auto second1 = std::make_shared<Forward_List_Node<int>>( 10 );

    first->next_  = first1;
    first1->next_ = a;
    a->next_      = b;
    b->next_      = c;

    second->next_  = second1;
    second1->next_ = a;

    auto result = intersection_hash( first, second );
    ASSERT_EQ( a, result );
}

TEST( INTERSECTION_LIST, SAME_LIST ) {
    auto first = std::make_shared<Forward_List_Node<int>>( 0 );
    auto a     = std::make_shared<Forward_List_Node<int>>( 1 );
    auto b     = std::make_shared<Forward_List_Node<int>>( 2 );
    auto c     = std::make_shared<Forward_List_Node<int>>( 3 );

    first->next_ = a;
    a->next_     = b;
    b->next_     = c;

    auto result = find_intersection( first, first );
    ASSERT_EQ( first, result );
}

TEST( INTERSECTION_LIST, CYCLE_AFTER_ONE ) {
    auto first = std::make_shared<Forward_List_Node<int>>( 0 );
    auto a     = std::make_shared<Forward_List_Node<int>>( 1 );
    auto b     = std::make_shared<Forward_List_Node<int>>( 2 );
    auto c     = std::make_shared<Forward_List_Node<int>>( 3 );

    auto second = std::make_shared<Forward_List_Node<int>>( 0 );

    first->next_ = a;
    a->next_     = b;
    b->next_     = c;

    second->next_ = a;

    auto result = find_intersection( first, second );
    ASSERT_EQ( a, result );
}

TEST( INTERSECTION_LIST, CYCLE_AFTER_TWO ) {
    auto first  = std::make_shared<Forward_List_Node<int>>( 0 );
    auto first1 = std::make_shared<Forward_List_Node<int>>( 10 );
    auto a      = std::make_shared<Forward_List_Node<int>>( 1 );
    auto b      = std::make_shared<Forward_List_Node<int>>( 2 );
    auto c      = std::make_shared<Forward_List_Node<int>>( 3 );

    auto second  = std::make_shared<Forward_List_Node<int>>( 0 );
    auto second1 = std::make_shared<Forward_List_Node<int>>( 10 );

    first->next_  = first1;
    first1->next_ = a;
    a->next_      = b;
    b->next_      = c;

    second->next_  = second1;
    second1->next_ = a;

    auto result = find_intersection( first, second );
    ASSERT_EQ( a, result );
}