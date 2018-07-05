
#pragma once

#include <initializer_list>

namespace algorithm {
    struct bst_int_node {
        int value;
        bst_int_node* left;
        bst_int_node* right;
        bst_int_node* parent;

        bst_int_node(int value_ = 0, bst_int_node* left_ = nullptr, bst_int_node* right_ = nullptr, bst_int_node* parent_ = nullptr) :
                value(value_), left(left_), right(right_), parent(parent_) {}
    };

    inline bst_int_node* insert(bst_int_node* root, int value) {
        if(!root) return new bst_int_node(value);
        bst_int_node* temp;
        if(root->value == value) return root;
        else if(value < root->value) {
            temp = insert(root->left, value);
            root->left = temp;
        }
        else {
            temp = insert(root->right, value);
            root->right = temp;
        }
        temp->parent = root;
        return root;
    }

    inline bst_int_node* insert(const std::initializer_list<int>& input) {
        if(!input.size()) return nullptr;
        auto root = insert(nullptr, *input.begin());
        for(auto elem = input.begin() + 1; elem < input.end(); ++elem) {
            insert(root, *elem);
        }
        return root;
    }
}