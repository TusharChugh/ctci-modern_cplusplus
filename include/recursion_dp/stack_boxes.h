/**
 * @brief Stack of Boxes
 * You have a stack of n boxes, with widths Wi'  heights hi' and depths di. The boxes cannot be
 * rotated and can only be stacked on top of one another if each box in the stack is strictly larger
 * than the box above it in width, height, and depth. Implement a method to compute the height of
 * the tallest possible stack. The height of a stack is the sum of the heights of each box.
 *
 * @file stack_boxes.h
 * @author Tushar Chugh
 */

#pragma once
#include <algorithm>
#include <vector>

namespace algorithm {
struct Box {
    unsigned int length;
    unsigned int breadth;
    unsigned int height;

    bool empty() const noexcept {
        return ( length == 0 || breadth == 0 || height == 0 );
    }
};

bool is_valid_placement( const Box& top, const Box& bottom ) {
    return ( bottom.height > top.height ) && ( bottom.breadth > top.breadth ) &&
           ( bottom.length > top.length );
}

unsigned int stack_boxes( const std::vector<Box>& boxes, const Box& last_box, size_t index,
                          std::vector<unsigned int>& stacked_heights ) {
    if ( index >= boxes.size() ) return 0;
    const auto& current_box         = boxes.at( index );
    unsigned int height_with_bottom = 0;
    if ( last_box.empty() || is_valid_placement( current_box, last_box ) ) {
        if ( stacked_heights[index] == 0 ) {
            stacked_heights[index] = stack_boxes( boxes, current_box, index + 1, stacked_heights );
            stacked_heights[index] += current_box.height;
        }
        height_with_bottom = stacked_heights[index];
    }
    unsigned int height_without_bottom = stack_boxes( boxes, last_box, index + 1, stacked_heights );
    return std::max( height_with_bottom, height_without_bottom );
}

int tallest_stack( std::vector<Box> boxes ) {
    // sort boxes based on height
    std::sort( boxes.begin(), boxes.end(),
               []( const Box& box1, const Box& box2 ) { return box1.height > box2.height; } );
    std::vector<unsigned int> stacked_heights( boxes.size() );
    Box empty_box{0, 0, 0};
    return stack_boxes( boxes, empty_box, 0, stacked_heights );
}

} // namespace algorithm