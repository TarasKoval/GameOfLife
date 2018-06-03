cmake_minimum_required(VERSION 3.5.2)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${GameOfLife_SOURCE_DIR}/build)

add_executable(GameOfLife
# use one of three:
        sources/main.cpp

        headers/Game.h
        headers/functions.h
        sources/Game.cpp
        sources/functions.cpp
        )
