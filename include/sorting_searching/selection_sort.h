/**
 * @brief Templated selection sort
 *
 * @file selection_sort.h
 * @author Tushar Chugh
 */

#pragma once

#include <algorithm>

namespace algorithm {

template <typename ForwardIt, typename Compare>
void selection_sort( ForwardIt first, ForwardIt last, Compare comp ) {
    for ( ForwardIt current = first; first != last; ++first ) {
        ForwardIt minimum = first;
        ForwardIt other   = first;
        ++other;

        while ( other != last ) {
            if ( comp( *other, *minimum ) ) minimum = other;
            ++other;
        }
        if ( minimum != current ) {
            using std::swap;
            swap( *minimum, *first );
        }
    }
}

template <typename ForwardIt> void selection_sort( ForwardIt first, ForwardIt second ) {
    selection_sort( first, second,
                    std::less<typename std::iterator_traits<ForwardIt>::value_type>() );
}
} // namespace algorithm