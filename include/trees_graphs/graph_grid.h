/**
 * @brief Simple representation of a graph of 2D grid
 *
 * @file graph_grid.h
 * @author Tushar Chugh
 */

#pragma once

#include <cstddef>
#include <utility>
#include <vector>

namespace algorithm {

/**
 * @brief Simple representation of a graph of 2D grid
 * The graph is implemented with 2D vector with int as the cost type
 * The padding is doe in all four directions of the 2D matrix
 * Indexing should start from (1,1) to (num_rows, num_cols) and not (0,0)
 */
class graph_grid {
public:
    using cost_t = int;
    using cell_t = typename std::pair<size_t, size_t>;

    graph_grid() = default;

    /**
     * @brief Construct a new graph grid object
     * A padding of 1 layers is adding to all 4 directions
     * @param rows number of rows
     * @param cols number of cols
     * @param cost default cost of the each cell
     */
    explicit graph_grid( size_t rows, size_t cols, cost_t cost = cost_t{} )
        : rows_( rows ), cols_( cols ), grid_( rows + 2, std::vector<cost_t>( cols + 2, cost ) ) {}

    // copy constructor
    graph_grid( graph_grid& other ) {
        this->rows_ = other.rows_;
        this->cols_ = other.cols_;
        grid_       = other.grid_;
    }

    // move constructor
    graph_grid( graph_grid&& other ) {
        this->rows_ = other.rows_;
        this->cols_ = other.cols_;
        grid_       = std::move( other.grid_ );
    }

    bool valid_loc( size_t row, size_t col ) const noexcept {
        if ( row < 1 || row > rows_ ) return false;
        if ( col < 1 || col > cols_ ) return false;
        return true;
    }

    bool valid_loc( cell_t loc ) const noexcept {
        return valid_loc( loc.first, loc.second );
    }

    auto left( cell_t cell ) const noexcept {
        return std::make_pair( cell.first, cell.second - 1 );
    }

    auto right( cell_t cell ) const noexcept {
        return std::make_pair( cell.first, cell.second + 1 );
    }

    auto up( cell_t cell ) const noexcept {
        return std::make_pair( cell.first - 1, cell.second );
    }

    auto down( cell_t cell ) const noexcept {
        return std::make_pair( cell.first + 1, cell.second );
    }

    std::vector<cell_t> neighbors( std::pair<size_t, size_t> cell ) {
        if ( !valid_loc( cell ) ) throw std::__throw_invalid_argument;

        std::vector<std::pair<size_t, size_t>> neighbors;
        if ( valid_loc( left( cell ) ) ) neighbors.push_back( left( cell ) );
        if ( valid_loc( right( cell ) ) ) neighbors.push_back( right( cell ) );
        if ( valid_loc( up( cell ) ) ) neighbors.push_back( up( cell ) );
        if ( valid_loc( down( cell ) ) ) neighbors.push_back( down( cell ) );

        return neighbors;
    }

    cost_t cost( size_t row, size_t col ) const {
        if ( !valid_loc( row, col ) ) throw std::__throw_invalid_argument;
        return grid_.at( row ).at( col );
    }

    cost_t cost( cell_t cell ) const {
        return cost( cell.first, cell.second );
    }

    void update_cost( size_t row, size_t col, cost_t cost ) {
        if ( !valid_loc( row, col ) ) throw std::__throw_invalid_argument;
        grid_.at( row ).at( col ) = cost;
    }

    void update_cost( cell_t cell, cost_t cost ) {
        update_cost( cell.first, cell.second, cost );
    }

    std::pair<size_t, size_t> size() {
        return std::make_pair( rows_, cols_ );
    }

private:
    size_t rows_;
    size_t cols_;
    std::vector<std::vector<cost_t>> grid_;
};
} // namespace algorithm