/**
 * @brief Route Between Nodes
 * Given a directed graph, design an algorithm to find out whether there is a route between two
 * nodes.
 *
 * @file route_nodes.h
 * @author Tushar Chugh
 */

#pragma once

#include <queue>
#include <unordered_set>
#include "adj_list_graph.h"

namespace algorithm {
bool route_between_nodes( const adj_list_graph<true>& graph, size_t to, size_t from ) {
    if ( to == from ) return true;

    std::unordered_set<size_t> visited;
    std::queue<size_t> pending;
    pending.push( to );

    while ( !pending.empty() ) {
        const auto& front_node = pending.front();
        pending.pop();
        for ( const auto& adj : graph.adjacent_vertices( front_node ) ) {
            if ( adj == from ) return true;
            if ( visited.find( pending.front() ) != visited.end() ) {
                pending.push( adj );
            }
        }
        visited.insert( front_node );
    }
    return false;
}
} // namespace algorithm