#include "event_manager.hpp"


EventManager::EventManager() {
}

EventManager::~EventManager() {
}

EventManager &EventManager::getInstance() {
    static EventManager instance{};
    return instance;
}