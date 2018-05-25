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
    for ( auto set_element : std::vector<std::vector<T>>(output) ) {
        set_element.push_back( element );
        output.push_back( set_element );
    }
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