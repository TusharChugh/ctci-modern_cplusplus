/**
 * @brief Power Set: Write a method to return all subsets of a set.
 *
 * @file power_set.h
 * @author Tushar Chugh
 */

#pragma once

#include <iostream>
#include <vector>

namespace algorithm {

template <typename T>
void power_set_helper( const T& element, std::vector<std::vector<T>>& output ) {
    std::vector<std::vector<T>> more_subsets;
    for ( auto set_elements : output ) {
        set_elements.push_back( element );
        more_subsets.push_back( set_elements );
    }
    std::move( more_subsets.begin(), more_subsets.end(), std::back_inserter( output ) );
    output.emplace_back( std::initializer_list<T>{element} );
}

template <typename T> std::vector<std::vector<T>> power_set( const std::vector<T>& input ) {
    std::vector<std::vector<T>> output;
    for ( const auto& element : input ) {
        power_set_helper( element, output );
    }
    return output;
}

} // namespace algorithm