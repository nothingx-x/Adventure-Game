#pragma once
#include <functional>
#include <typeindex>

#include "event/event.hpp"


class EventManager {
private:
    std::unordered_map<std::type_index,
    std::vector<std::function<void(const Event &)> > > subscribers;

public:
    EventManager();

    ~EventManager();

    EventManager(const EventManager &p_other) = delete;

    EventManager(EventManager &&p_other) noexcept = delete;

    EventManager &operator=(const EventManager &p_other) = delete;

    EventManager &operator=(EventManager &&p_other) noexcept = delete;

    static EventManager &getInstance();

    template<class E>
        requires std::derived_from<E, Event>
    void call(const E &event) {
        auto it = subscribers.find(std::type_index(typeid(E)));
        if (it == subscribers.end()) return;

        auto snapshot = it->second; // reentrancy: see below
        for (auto &fn: snapshot) fn(event);
    };

    template<class E>
        requires std::derived_from<E, Event>
    void registerSubscriber(std::function<void(const E &event)> subscriber) {
        subscribers[std::type_index(typeid(E))].push_back(
            [fn = std::move(subscriber)](const Event &e) {
                fn(static_cast<const E &>(e)); // safe: bucket is typeid(T)
            });
    };
};
