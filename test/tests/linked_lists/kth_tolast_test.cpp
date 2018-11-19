#include <linked_lists/kth_tolast.h>
#include <gtest/gtest.h>

using algorithm::Forward_List;
using algorithm::kth_tolast_runner;

TEST( KTH_TOLAST, EMPTY_LIST ) {
    Forward_List<int> list;
    auto last = kth_tolast_runner( list, 1 );
    ASSERT_EQ( nullptr, last );
}

TEST( KTH_TOLAST, INVALID_K_VALUE ) {
    std::array<int, 5> input{5, 4, 3, 2, 1};
    Forward_List<int> list;
    for ( auto& num : input ) {
        list.push_front( num );
    }

    auto last = kth_tolast_runner( list, 6 );
    ASSERT_EQ( nullptr, last );
}

TEST( KTH_TOLAST, FIVE_ELEMENTS ) {
    std::array<int, 5> input{5, 4, 3, 2, 1};
    Forward_List<int> list;
    for ( auto& num : input ) {
        list.push_front( num );
    }

    auto last = kth_tolast_runner( list, 1 );
    ASSERT_EQ( 5, last->value_ );

    auto second_last = kth_tolast_runner( list, 2 );
    ASSERT_EQ( 4, second_last->value_ );

    auto third_last = kth_tolast_runner( list, 3 );
    ASSERT_EQ( 3, third_last->value_ );

    auto fourth_last = kth_tolast_runner( list, 4 );
    ASSERT_EQ( 2, fourth_last->value_ );

    auto five_last = kth_tolast_runner( list, 5 );
    ASSERT_EQ( 1, five_last->value_ );
}