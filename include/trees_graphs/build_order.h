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
// better would be to implement a class the dfs function has too many arguments - ugly

void dfs_build(char project, std::vector<char>& ordered_projects, const std::unordered_multimap<char, char>& dependency_pairs,
               std::unordered_set<char>& built, std::unordered_set<char>& built_same_node) {
    built.insert(project);
    built_same_node.insert(project);

    auto range_adj = dependency_pairs.equal_range(project);
    for (auto start = range_adj.first; start != range_adj.second; ++start) {
        auto proj = (*start).second;
        if(built_same_node.find(proj) != built_same_node.end())
            std::__throw_invalid_argument("error: cyclic dependency");
        if(built.find(proj) == built.end())
            dfs_build(proj, ordered_projects, dependency_pairs, built, built_same_node);
    }
    ordered_projects.push_back(project);
}

std::vector<char> build_order( std::vector<char> projects,
                               const std::unordered_multimap<char, char>& dependency_pairs ) {
    std::vector<char> ordered_projects;
    std::unordered_set<char> built;

     for ( const auto& project : projects ) {
         std::unordered_set<char> built_same_root;
         if(built.find(project) == built.end())
            dfs_build(project, ordered_projects, dependency_pairs, built, built_same_root);
     }
    return  ordered_projects;
}
} // namespace algorithm