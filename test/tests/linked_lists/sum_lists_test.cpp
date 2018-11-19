#include <linked_lists/sum_lists.h>
#include <gtest/gtest.h>

using algorithm::Forward_List;
using algorithm::sum_lists;
using node_pointer_int = typename std::shared_ptr<algorithm::Forward_List_Node<int>>;

// void print_list( node_pointer_int head ) {
//     while ( head ) {
//         std::cout << head->value_ << " ";
//         head = head->next_;
//     }
//     std::cout << std::endl;
// }

TEST( SUM_LIST, EMPTY_LIST ) {
    Forward_List<int> list;

    node_pointer_int result = sum_lists( list.front(), list.front() );

    ASSERT_EQ( nullptr, result );
}

TEST( SUM_LIST, EQUAL_THREE_ELEMENTS ) {
    std::array<int, 3> input1{6, 1, 7};
    Forward_List<int> list1;
    for ( auto& num : input1 ) {
        list1.push_front( num );
    }

    std::array<int, 3> input2{2, 9, 5};
    Forward_List<int> list2;
    for ( auto& num : input2 ) {
        list2.push_front( num );
    }

    node_pointer_int result   = sum_lists( list1.front(), list2.front() );
    std::array<int, 3> output = {2, 1, 9};
    auto head                 = result;
    for ( size_t i = 0; i < output.size(); ++i ) {
        ASSERT_EQ( output[i], head->value_ );
        head = head->next_;
    }
}

TEST( SUM_LIST, INPUT1_LESS_SIZE ) {
    std::array<int, 2> input1{6, 1};
    Forward_List<int> list1;
    for ( auto& num : input1 ) {
        list1.push_front( num );
    }

    std::array<int, 3> input2{2, 9, 5};
    Forward_List<int> list2;
    for ( auto& num : input2 ) {
        list2.push_front( num );
    }

    node_pointer_int result   = sum_lists( list1.front(), list2.front() );
    std::array<int, 3> output = {6, 5, 3};
    auto head                 = result;
    for ( size_t i = 0; i < output.size(); ++i ) {
        ASSERT_EQ( output[i], head->value_ );
        head = head->next_;
    }
}

TEST( SUM_LIST, INPUT2_LESS_SIZE ) {
    std::array<int, 3> input1{2, 9, 5};
    Forward_List<int> list1;
    for ( auto& num : input1 ) {
        list1.push_front( num );
    }

    std::array<int, 2> input2{6, 1};
    Forward_List<int> list2;
    for ( auto& num : input2 ) {
        list2.push_front( num );
    }

    node_pointer_int result   = sum_lists( list1.front(), list2.front() );
    std::array<int, 3> output = {6, 5, 3};
    auto head                 = result;
    for ( size_t i = 0; i < output.size(); ++i ) {
        ASSERT_EQ( output[i], head->value_ );
        head = head->next_;
    }
}