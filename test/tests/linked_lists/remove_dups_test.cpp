#include "include/linked_lists/remove_dups.h"
#include <gtest/gtest.h>
#include <iostream>
#include "include/linked_lists/forward_list.h"

using algorithm::Forward_List;
using algorithm::remove_duplicates_map;

template<class T> void print_list( Forward_List<T>& input ) {
    auto head = input.begin();
    while ( head ) {
        std::cout << head->value_ << " ";
        head = head->next_;
    }
    std::cout << std::endl;
}

TEST( REMOVE_DUPS, ONE_DUPLICATE ) {
    std::array<int, 5> input{1, 2, 2, 3, 4};
    Forward_List<int> list;
    for ( auto& num : input ) {
        list.push_front( num );
    }
    print_list( list );
    remove_duplicates_map( list );
    print_list( list );
    std::vector<int> output = {4, 3, 2, 1};
    auto head               = list.begin();
    for ( size_t i = 0; i < output.size(); ++i ) {
        ASSERT_EQ( output[i], head->value_ );
        head = head->next_;
    }
}