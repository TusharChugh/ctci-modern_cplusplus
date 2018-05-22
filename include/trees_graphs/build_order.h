/**
 * @brief Build Order
 * You are given a list of projects and a list of dependencies (which is a list of pairs of
 * projects, where the second project is dependent on the first project). All of a project's
 * dependencies must be built before the project is. Find a build order that will allow the projects
 * to be built. If there is no valid build order, return an error. EXAMPLE Input: projects: a, b, c,
 * d, e, f dependencies: (a, d), (f, b), (b, d), (f, a), (d, c) Output: f, e, a, b, d, c
 *
 * @file build_order.h
 * @author Tushar Chugh
 */

#pragma once

#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace algorithm {

std::vector<char> build_order( std::vector<char> projects,
                               std::unordered_multimap<char, char> dependency_pairs ) {
    std::vector<char> ordered_projects;
    std::unordered_set<char> built;

    // for ( const auto& project : projects ) {
    //     std::stack<char>
    //     if ( built.find( project ) == built.end() ) {
    //         built.insert( project );
    //         auto range_adj = dependency_pairs.equal_range( project );
    //         for ( auto start = range_adj.first; start != range_adj.second; ++start ) {

    //         }
    //     }
    // }
}
} // namespace algorithm