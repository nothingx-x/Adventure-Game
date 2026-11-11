#pragma once
#include <vector>


class Node;

class Tree {
private:
    Node *root = nullptr;
    std::vector<Node *> children;
    size_t current_index = 0;

public:
    Tree() = default;
    ~Tree() = default;

    void add_child(Node *child) {
        children.push_back(child);
    }

    void increment() {
        current_index = std::min(current_index + 1, children.size());
    }

    [[nodiscard]] Node *get_current() const {
        return children[current_index];
    }

    [[nodiscard]] Node * get_root() const {
        return root;
    }

    void set_root(Node *p_root) {
        root = p_root;
    }

    [[nodiscard]] size_t get_current_index() const {
        return current_index;
    }

    void set_current_index(size_t p_current_index) {
        current_index = p_current_index;
    }

    size_t get_children_count() const {
        return children.size();
    }
};
