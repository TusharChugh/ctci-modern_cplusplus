#include "include/linked_lists/partition.h"
#include <gtest/gtest.h>

using algorithm::Forward_List;
using algorithm::partition_stable;
using node_pointer_int = typename std::shared_ptr<algorithm::Forward_List_Node<int>>;

template<class T> void print_list( Forward_List<T>& input ) {
    auto head = input.front();
    while ( head ) {
        std::cout << head->value_ << " ";
        head = head->next_;
    }
    std::cout << std::endl;
}


void print_list( node_pointer_int head ) {
    while ( head ) {
        std::cout << head->value_ << " ";
        head = head->next_;
    }
    std::cout << std::endl;
}

TEST( PARTITION_LIST, EMPTY_LIST ) {
    Forward_List<int> list;

    node_pointer_int result= partition_stable( list.front(), 1 );

    ASSERT_EQ( nullptr, result );
}

//TEST( REMOVE_DUPS, ONE_ELEMENT ) {
//    int input = 1;
//    Forward_List<int> list;
//    list.push_front( input );
//
//    node_pointer_int = remove_duplicates_map( list );
//
//    ASSERT_EQ( input, list.front()->value_ );
//}

TEST( PARTITION_LIST, SEVEN_ELEMENTS ) {
    std::array<int, 7> input{3, 5, 8, 5, 10, 2, 1};
    Forward_List<int> list;
    for ( auto& num : input ) {
        list.push_front( num );
    }

    node_pointer_int result= partition_stable( list.front(), 5 );
    std::array<int, 7> output = {1, 2, 3, 10, 5, 8, 5};
    auto head               = result;
    for ( size_t i = 0; i < output.size(); ++i ) {
        ASSERT_EQ( output[i], head->value_ );
        head = head->next_;
    }
}