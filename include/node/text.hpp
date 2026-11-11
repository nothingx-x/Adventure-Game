#pragma once
#include <string>
#include <utility>
#include "node.hpp"


class TextNode : public Node {
private:
    std::string content;
    Node *next = nullptr;

public:
    explicit TextNode(std::string p_content)
        : content(std::move(p_content)) {
    }

    TextNode(std::string p_content, Node *p_next)
        : content(std::move(p_content)),
          next(p_next) {
    }

    ~TextNode() override = default;

    std::string get_content() {
        return content;
    };

    [[nodiscard]] Node *get_next() const {
        return next;
    };

    void set_next(Node *p_next) {
        next = p_next;
    };
};
