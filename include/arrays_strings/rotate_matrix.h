/**
 * @brief
 * Given an image represented by an NxN matrix, where each pixel in  the image is 4 bytes.
 * Write a method to rotate the image by 90 degrees. (an you do this in place?
 *
 * @file rotate_matrix.h
 * @author Tushar Chugh
 */
#pragma once

#include <assert.h>
#include <cstddef>
#include <vector>

#include <iostream>

namespace algorithm {

// image type of 32 bits
using image_type = std::vector<std::vector<__UINT32_TYPE__>>;

/**
 * @brief print an image
 *
 * @param image image of type image_type
 */
void print_image( image_type& image ) {
    for ( auto& row : image ) {
        for ( auto& col : row ) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Rotate a n NxN image by 90 degrees
 *
 * @param image image of type image type
 */
void rotate_matrix( image_type& image ) {
    if ( !image.size() ) return;
    if ( image.size() != image[0].size() ) std::__throw_invalid_argument( "Not a square image" );

    size_t start = 0;
    size_t end   = image.size() - 1;

    while ( start < end ) {
        for ( size_t index = 0; index < end - start; ++index ) {
            auto top_right              = image[start + index][end];
            image[start + index][end]   = image[start][start + index];
            auto bottom_right           = image[end][end - index];
            image[end][end - index]     = top_right;
            auto bottom_left            = image[end - index][start];
            image[end - index][start]   = bottom_right;
            image[start][start + index] = bottom_left;
        }
        ++start;
        --end;
    }
}
} // namespace algorithm