#pragma once

#include "forward_list.h"
#include <unordered_set>

namespace algorithm {
    template <typename T>
    std::shared_ptr<Forward_List_Node<T>> intersection_hash(std::shared_ptr<Forward_List_Node<T>> input1_node,
                                                            std::shared_ptr<Forward_List_Node<T>> input2_node) {

        std::unordered_set<std::shared_ptr<Forward_List_Node<T>>> input1_nodes;
        while(input1_node != nullptr) {
            input1_nodes.insert(input1_node);
            input1_node = input1_node->next_;
        }

        while(input2_node != nullptr) {
            if(input1_nodes.find(input2_node) != input1_nodes.end())
                return input2_node;
            input2_node = input2_node->next_;
        }

        return nullptr;
}
}