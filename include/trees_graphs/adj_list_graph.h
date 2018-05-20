/**
 * @brief Simple graph implementation using adjency list
 * Non-templated - only handles int
 * templatized version becomes too complicates. Idea is to focus on algo's
 * @file adj_list_graph.h
 * @author Tushar Chugh
 */

#pragma once

#include <stddef.h>
#include <forward_list>
#include <vector>

namespace algorithm {

class adj_list_graph {

public:
    using value_type      = int;
    using list_type       = typename std::forward_list<int>;
    using graph_type      = typename std::vector<std::forward_list<int>>;
    using const_reference = const std::forward_list<int>&;
    using iterator        = graph_type::iterator;

    adj_list_graph( size_t num_vertices = 0, bool directed = false )
        : vertices_{num_vertices}, num_vertices_( num_vertices ), num_edges_{0},
          directed_( directed ) {}

    size_t num_vertices() const noexcept {
        return num_vertices_;
    }

    size_t num_edges() const noexcept;

    bool empty() const noexcept {
        return num_vertices_ == 0;
    }

    void add_edge( size_t to, size_t from ) {
        add_edge_helper( to, from );
        if ( !directed_ ) add_edge_helper( from, to );
        ++num_edges_;
    }

    const_reference adjacent_vertices( size_t vertex ) {
        return vertices_.at( vertex );
    }

    iterator begin() {
        return vertices_.begin();
    }

    iterator end() {
        return vertices_.end();
    }

private:
    std::vector<std::forward_list<int>> vertices_;
    const size_t num_vertices_;
    size_t num_edges_;
    const bool directed_;

    void add_edge_helper( size_t to, size_t from ) {
        vertices_.at( to ).push_front( from );
    }
};
} // namespace algorithm