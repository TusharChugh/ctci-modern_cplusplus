#pragma once

#include <unordered_map>
#include <string>
#include <memory>

class Trie {
    struct TrieNode{
        bool _is_word;
        std::unordered_map<char, TrieNode*> _children;
        explicit TrieNode(bool is_word= false, std::unordered_map<char, TrieNode*> children = std::unordered_map<char, TrieNode*> {}) :
        _is_word(is_word), _children(std::move(children)) {}
    };

    std::unique_ptr<TrieNode> startNode;
public:
    /** Initialize your data structure here. */
    Trie() {
        startNode = std::make_unique<TrieNode>();
    }

    /** Inserts a word into the trie. */
    void insert(std::string word) {
        auto node = startNode.get();
        for(auto letter : word) {
            if(node->_children.find(letter) == node->_children.end()) {
                auto child = new TrieNode;
                node->_children.emplace(letter, child);
            }
            node = node->_children.at(letter);
        }
        node->_is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        auto node = startNode.get();
        for(auto letter : word) {
            if(node->_children.find(letter) == node->_children.end())
                return false;
            node = node->_children.at(letter);
        }
        return node->_is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        auto node = startNode.get();
        for(auto letter : prefix) {
            if(node->_children.find(letter) == node->_children.end())
                return false;
            node = node->_children.at(letter);
        }
        return true;
    }
};