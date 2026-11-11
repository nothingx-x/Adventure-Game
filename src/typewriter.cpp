#include "typewriter.hpp"

#include "event_manager.hpp"
#include "event/animation_end_event.hpp"


void Typewriter::animate(const std::string &text) {
    current = text;
    i = 0;
    startTime = std::chrono::high_resolution_clock::now();
}

void Typewriter::tick() {
    if (current.empty()) {
        return;
    }

    if (i >= current.size()) {
        current = "";
        i = 0;
        std::putchar('\n');
        std::fflush(stdout);
        end();
        return;
    }

    const char c = current.at(i);
    std::putchar(c);
    std::fflush(stdout);
    ++i;
}

void Typewriter::end() {
    EventManager &event_manager = EventManager::getInstance();
    endTime = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    const AnimationEndEvent event{duration};

    event_manager.call<AnimationEndEvent>(event);
}

bool Typewriter::is_finished() const {
    if (current.empty()) {
        return true;
    }

    if (i >= current.size()) {
        return true;
    }

    return false;
}
