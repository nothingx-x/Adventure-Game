#include <chrono>
#include <cstdio>
#include <iostream>
#include <thread>
#include <typewriter.hpp>

#include "event_manager.hpp"
#include "game_manager.hpp"
#include "tree.hpp"
#include "event/animation_end_event.hpp"
#include "node/text.hpp"

static auto now() {
    return std::chrono::system_clock::now();
}

int main(int argc, char *argv[]) {
    /*
     Adventure Game
     Adventure Game is a text based game which
     players can pick an option from a, b, c, d
     after player pick an option there will be a way to handle it
     handler either could go to next dialogue or end the game.
     a game could have multiple ending with one winning
     */

    // You are a lost in jungle. nearby is a boat, what should we do?
    // A- Use boat
    // B- Explore Jungle
    // C- Go Backward
    // D- Go Forward

    // Each of these options is a node.
    // A node can have next, content

    Tree tree{};

    // nodes
    TextNode root{"Hello world"};
    TextNode node1{"Another text"};

    root.set_next(&node1);

    tree.set_root(&root);
    tree.add_child(&root);
    tree.add_child(&node1);

    Typewriter tw;
    GameManager game_manager {tree, tw};
    auto start = now();

    EventManager::getInstance().registerSubscriber<AnimationEndEvent>([&game_manager](const AnimationEndEvent &event) {
        game_manager.advance();
    });

    game_manager.start();
    using namespace std::chrono_literals;
    while (true) {
        tw.tick();
        start += 50ms;
        std::this_thread::sleep_until(start);
    }
}
