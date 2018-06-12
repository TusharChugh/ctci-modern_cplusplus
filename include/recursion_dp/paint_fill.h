/**
 * @brief Paint Fill
 * Implement the "paint fill" function that one might see on many image editing programs. That is,
 * given a screen (represented by a two-dimensional array of colors), a point, and a new color, fill
 * in the surrounding area until the color changes from the original color.
 *
 * @file paint_fill.h
 * @author Tushar Chugh
 */

#pragma once

#include <cstddef>
#include <vector>

namespace algorithm {

void fill_paint( std::vector<std::vector<unsigned short>>& image, int row, int col,
                 unsigned short old_color, int new_color ) {
    // check boundaries
    if ( row < 0 || row >= image.size() || col < 0 || col >= image[0].size() ) return;
    if ( image[row][col] == old_color ) {
        image[row][col] = new_color;
        fill_paint( image, row - 1, col, old_color, new_color );
        fill_paint( image, row + 1, col, old_color, new_color );
        fill_paint( image, row, col - 1, old_color, new_color );
        fill_paint( image, row, col + 1, old_color, new_color );
    }
}

void fill_paint( std::vector<std::vector<unsigned short>>& image, int row, int col,
                 unsigned short color ) {
    if ( image[row][col] == color ) return;
    fill_paint( image, row, col, image[row][col], color );
}

} // namespace algorithm