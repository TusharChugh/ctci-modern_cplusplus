#include <initializer_list>

struct List_Node {
    int val;
    List_Node* next;
    List_Node(int value = 0, List_Node* next_node = nullptr) : val(value), next(next_node) {}
};

inline List_Node* make_list(const std::initializer_list<int>& input) {
    List_Node* result_head = nullptr;

    for(const auto& in : input) {
        List_Node* node = new List_Node(in, result_head);
        result_head = node;
    }

    return result_head;
}

