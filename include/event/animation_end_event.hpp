#pragma once
#include <chrono>

#include "event.hpp"


class AnimationEndEvent : public Event {
private:
    std::chrono::duration<double> duration{};
public:
    AnimationEndEvent() = default;

    ~AnimationEndEvent() override {};

    explicit AnimationEndEvent(const std::chrono::duration<double> &p_duration)
        : duration(p_duration) {
    }

    [[nodiscard]] std::chrono::duration<double> get_duration() const {
        return duration;
    }
};
