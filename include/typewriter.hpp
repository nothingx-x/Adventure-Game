#pragma once
#include <chrono>
#include <string>


class Typewriter {
private:
    std::string current;
    size_t i = 0;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;

public:
    void animate(const std::string &text);

    void tick();

    void end();

    [[nodiscard]] bool is_finished() const;
};
