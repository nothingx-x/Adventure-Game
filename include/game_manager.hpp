#pragma once
#include <utility>

#include "tree.hpp"
#include "typewriter.hpp"


class GameManager {
private:
    Tree tree;
    Typewriter &tw;
public:
    GameManager(const Tree &p_tree, Typewriter &p_tw)
        : tree(p_tree),
          tw(p_tw) {
    }

    ~GameManager() = default;

    void start() const;
    void advance();
};
