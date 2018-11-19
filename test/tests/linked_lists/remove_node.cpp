#include <linked_lists/remove_node.h>
#include <gtest/gtest.h>

using algorithm::Forward_List;
using algorithm::remove_node;

template<class T> void print_list( Forward_List<T>& input ) {
    auto head = input.front();
    while ( head ) {
        std::cout << head->value_ << " ";
        head = head->next_;
    }
    std::cout << std::endl;
}

// Funtion doesn't accept nullptr
// TEST( REMOVE_NODE, NULLPTR_NODE ) {
//     ASSERT_EQ( nullptr, remove_node( nullptr ) );
// }

TEST( REMOVE_NODE, ONE_ELEMENT ) {
    int input = 1;
    Forward_List<int> list;
    list.push_front( input );

    remove_node( list.front() );

    ASSERT_EQ( input, list.front()->value_ );
}

TEST( REMOVE_NODE, REMOVE_MIDDLE_1 ) {
    std::array<int, 5> input{1, 2, 2, 3, 4};
    Forward_List<int> list;
    for ( auto& num : input ) {
        list.push_front( num );
    }

    remove_node( list.front()->next_->next_ );

    std::vector<int> output = {4, 3, 2, 1};
    auto head               = list.front();
    for ( size_t i = 0; i < output.size(); ++i ) {
        ASSERT_EQ( output[i], head->value_ );
        head = head->next_;
    }
}

TEST( REMOVE_NODE, REMOVE_MIDDLE_0 ) {
    std::array<int, 5> input{1, 2, 2, 3, 4};
    Forward_List<int> list;
    for ( auto& num : input ) {
        list.push_front( num );
    }

    remove_node( list.front()->next_ );

    std::vector<int> output = {4, 2, 2, 1};
    auto head               = list.front();
    for ( size_t i = 0; i < output.size(); ++i ) {
        ASSERT_EQ( output[i], head->value_ );
        head = head->next_;
    }
}
