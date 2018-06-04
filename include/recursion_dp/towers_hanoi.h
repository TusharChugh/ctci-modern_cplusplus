/**
 * @brief Towers of Hanoi
 * In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of different sizes
 * which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size
 * from top to bottom (Le., each disk sits on top of an even larger one). You have the following
 * constraints: (1) Only one disk can be moved at a time. (2) A disk is slid off the top of one
 * tower onto another tower. (3) A disk cannot be placed on top of a smaller disk. Write a program
 * to move the disks from the first tower to the last using Stacks.
 *
 * @file towers_hanoi.h
 * @author Tushar Chugh
 */

#pragma once

#include <cstddef>
#include <stack>

namespace algorithm {

/**
 * @brief Represent tower as in towers of hanoi
 * adaptor on the top of stack
 */
class Tower {
public:
    Tower()  = default;
    ~Tower() = default;

    Tower( std::initializer_list<int> list_disks ) : disks( list_disks ) {}

    void push( int disk ) {
        disks.push( disk );
    }

    size_t size() const noexcept {
        return disks.size();
    }

    bool empty() const noexcept {
        return disks.empty();
    }

    int pop() {
        int disk = disks.top();
        disks.pop();
        return disk;
    }

    void move_top_to( Tower& other ) {
        other.push( this->pop() );
    }

    void move_disks( int count, Tower& destination, Tower& buffer ) {
        if ( count <= 0 ) return;
        move_disks( count - 1, buffer, destination );
        move_top_to( destination );
        buffer.move_disks( count - 1, destination, *this );
    }

    friend bool operator==( const Tower& left, const Tower& right );

private:
    std::stack<int> disks;
};

/**
 * @brief Equal operator needed for asserts in the tests
 *
 * @param left left operand
 * @param right right operand
 * @return true if equal
 * @return false if unequal
 */
bool operator==( const Tower& left, const Tower& right ) {
    return left.disks == right.disks;
}
} // namespace algorithm