cmake_minimum_required(VERSION 4.3)
project(Adventure)

set(CMAKE_CXX_STANDARD 23)

add_executable(Adventure src/main.cpp
        include/event/event.hpp
        include/event/animation_end_event.hpp
        include/event_manager.hpp
        include/game_manager.hpp
        include/node/node.hpp
        include/node/text.hpp
        include/tree.hpp
        include/typewriter.hpp
        src/typewriter.cpp
        src/event_manager.cpp
        src/game_manager.cpp
)

target_include_directories(Adventure PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)