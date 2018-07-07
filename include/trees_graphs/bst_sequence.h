#pragma once

#include <queue>
#include <cstddef>
#include "bst.h"

namespace algorithm {

    using node_raw_pointer = bst_node<int>* ;

    void bst_sequence_helper(bst_node<int>* node, std::queue<bst_node<int>*> pending, const size_t tree_size, std::vector<int> current, std::vector<std::vector<int>>& result) {
        if(!node) return;

        if(current.size() == tree_size) {
            result.push_back(current);
            return;
        }

        pending.push(node);
        current.push_back(node->value_);

        while(!pending.empty()) {
            auto pending_val = pending.back();
            pending.pop();
            bst_sequence_helper(pending_val->left_.get(), pending, tree_size, current, result);
            bst_sequence_helper(pending_val->right_.get(), pending, tree_size, current, result);
        }
    }

    std::vector<std::vector<int>> bst_sequence(const bst<int>& input) {
        std::vector<std::vector<int>> result;
        bst_sequence_helper(input.root(), std::queue<bst_node<int>*>{}, input.size(), std::vector<int>{}, result);
        return result;
    }
}