cmake_minimum_required(VERSION 3.5.2)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(GameOfLife
        src/main.cpp
        src/Game.cpp
        src/functions.cpp
        )
