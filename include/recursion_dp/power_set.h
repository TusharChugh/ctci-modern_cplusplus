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
template <typename T> void print_vector( const std::vector<T>& input ) {
    for ( const auto& elem : input )
        std::cout << elem << " ";
    std::cout << std::endl;
}

template <typename T> void print_vector( const std::vector<std::vector<T>>& input ) {
    std::cout << "before" << std::endl;
    for ( const auto& elem : input ) {
        for ( const auto& el : elem )
            std::cout << el << " ";
        std::cout << std::endl;
    }
    std::cout << "after" << std::endl;
}

template <typename T>
void power_set_helper( const T& element, std::vector<std::vector<T>>& output ) {
    for ( auto set_element : output ) {
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

// void power_set_helper( int element, std::vector<std::vector<int>>& output ) {
//     // print_vector( output );
//     for ( auto set_element : output ) {
//         // std::cout << "before" << std::endl;
//         print_vector( set_element );
//         set_element.push_back( element );
//         // std::cout << "after" << std::endl;
//         // print_vector( set_element );
//         output.push_back( std::move( set_element ) );
//     }
//     output.emplace_back( std::initializer_list<int>{element} );
//     print_vector( output );
// }

// std::vector<std::vector<int>> power_set( const std::vector<int>& input ) {
//     std::vector<std::vector<int>> output;
//     for ( const auto& element : input ) {
//         power_set_helper( element, output );
//     }
//     return output;
// }

} // namespace algorithm