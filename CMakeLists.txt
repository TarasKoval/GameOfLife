cmake_minimum_required(VERSION 3.5.1)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(GameOfLife
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/Game.cpp
        )

add_executable(tests EXCLUDE_FROM_ALL
        ${PROJECT_SOURCE_DIR}/src/Game.cpp
        ${PROJECT_SOURCE_DIR}/tests/functions.cpp
        ${PROJECT_SOURCE_DIR}/tests/test.cpp
        )
