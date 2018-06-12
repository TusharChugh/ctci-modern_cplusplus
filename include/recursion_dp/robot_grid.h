/**
 * @brief Robot in a Grid
 * Imagine a robot sitting on the upper left corner of grid with r rows and c columns. The robot can
 * only move in two directions, right and down, but certain cells are "off limits" such that the
 * robot cannot step on them. Design an algorithm to find a path for the robot from the top left to
 * the bottom right.
 *
 * @file robot_grid.h
 * @author Tushar Chugh
 */

#pragma once

#include <algorithm>
#include <queue>
#include <unordered_map>
#include "include/trees_graphs/graph_grid.h"

namespace algorithm {
using point          = typename std::pair<size_t, size_t>;
using Path           = typename std::vector<point>;
using Graph          = graph_grid;
using Location       = typename Graph::cell_t;
using cost_cell_pair = typename std::pair<Graph::cost_t, point>;
using Priority_queue = typename std::priority_queue<cost_cell_pair, std::vector<cost_cell_pair>,
                                                    std::greater<cost_cell_pair>>;
std::vector<std::pair<int, int>> directions = {std::pair<int, int>{1, 0},
                                               std::pair<int, int>{0, 1}};
struct cell_hash {
    inline std::size_t operator()( const std::pair<size_t, size_t>& v ) const noexcept {
        return v.first * 31 + v.second;
    }
};

void a_star_search( const Graph& graph, Location start, Location goal,
                    std::unordered_map<Location, Location, algorithm::cell_hash>& came_from ) {
    std::unordered_map<Location, Graph::cost_t, algorithm::cell_hash> cost_so_far;
    Priority_queue fringe;
    fringe.emplace( 0, start );

    came_from[start]   = start;
    cost_so_far[start] = 0;

    while ( !fringe.empty() ) {
        auto current = fringe.top().second; // get the elements with highest priority
        fringe.pop();

        if ( current == goal ) break;

        for ( auto next : graph.neighbors( current, directions ) ) {
            auto new_cost = cost_so_far.at( current ) + graph.cost( current );
            if ( cost_so_far.find( next ) == cost_so_far.end() ||
                 new_cost < cost_so_far.at( next ) ) {
                cost_so_far[next] = new_cost;
                came_from[next]   = current;
                auto priority     = new_cost + graph.manhattan_distance( next, goal );
                fringe.emplace( priority, next );
            }
        }
    }
}

Path reconstruct_path( Location start, Location goal,
                       std::unordered_map<Location, Location, algorithm::cell_hash> came_from ) {
    Path path;
    auto current = goal;
    while ( current != start ) {
        path.push_back( current );
        current = came_from.at( current );
    }
    path.push_back( start );
    std::reverse( path.begin(), path.end() );
    return path;
}

/**
 * @brief Note: using A* search here for fun. DFS/BFS would work fine.
 * Note: current algorithm will step on the obstacle depending on the cost of those.
 * This can be easily changed if it the cell is to be considered as a barrier
 *
 * @param graph
 * @param start
 * @param goal
 * @return Path
 */
Path find_path( const Graph& graph, Location start, Location goal ) {
    std::unordered_map<Location, Location, algorithm::cell_hash> came_from;
    a_star_search( graph, start, goal, came_from );
    return reconstruct_path( start, goal, came_from );
}
} // namespace algorithm