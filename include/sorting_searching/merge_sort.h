/**
 * @brief Templated implementation of merge sort
 *
 * @file merge_sort.h
 * @author Tushar Chugh
 */

#pragma once

#include <algorithm>
#include <cstddef>
#include <vector>

namespace algorithm {

template <typename RandomIt, typename Compare>
void merge( RandomIt first, RandomIt mid, RandomIt last, Compare comp,
            typename std::vector<typename std::iterator_traits<RandomIt>::value_type>::iterator
                copy_iterator ) {

    auto first_t         = first;
    auto copy_iterator_t = copy_iterator;
    auto mid_t           = mid;

    while ( first_t < mid && mid_t < last )
        *( copy_iterator_t++ ) = comp( *first_t, *mid_t ) ? *( first_t++ ) : *( mid_t++ );

    copy_iterator_t = std::move( first_t, mid, copy_iterator_t );
    copy_iterator_t = std::move( mid_t, last, copy_iterator_t );

    std::move( copy_iterator, copy_iterator_t, first );
}

template <typename RandomIt, typename Compare>
void merge_sort( RandomIt first, RandomIt last, Compare comp,
                 typename std::vector<typename std::iterator_traits<RandomIt>::value_type>::iterator
                     copy_iterator ) {
    const size_t size = std::distance( first, last );
    if ( size <= 1 ) return;

    auto mid = first;
    std::advance( mid, ( size / 2 ) );

    merge_sort( first, mid, comp, copy_iterator );
    merge_sort( mid, last, comp, copy_iterator );

    merge( first, mid, last, comp, copy_iterator );
}

template <typename RandomIt, typename Compare>
void merge_sort( RandomIt first, RandomIt last, Compare comp ) {
    std::vector<typename std::iterator_traits<RandomIt>::value_type> input_copy(
        std::distance( first, last ) );
    merge_sort( first, last, comp, input_copy.begin() );
}

template <class RandomIt> void merge_sort( RandomIt first, RandomIt last ) {
    merge_sort( first, last, std::less<typename std::iterator_traits<RandomIt>::value_type>() );
}

} // namespace algorithm