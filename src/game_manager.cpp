#include "game_manager.hpp"

#include "node/text.hpp"


void GameManager::start() const {
    if (auto *text = dynamic_cast<TextNode *>(tree.get_root())) {
        tw.animate(text->get_content());
    }
}

void GameManager::advance() {
    const size_t current_index = tree.get_current_index();
    if (current_index + 1 == tree.get_children_count()) {
        return;
    }

    tree.increment();
    Node *current = tree.get_current();

    if (auto *text = dynamic_cast<TextNode *>(current)) {
        tw.animate(text->get_content());
    }
}
