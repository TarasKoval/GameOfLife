cmake_minimum_required(VERSION 3.5.2)
project(mainGame)

set(CMAKE_CXX_STANDARD 11)

add_executable(mainGame
# use one of three:
        sources/main.cpp
#        sources/tests.cpp
#        sources/fastSimulation.cpp

        sources/Game.cpp
        sources/checkFilesForEquality.cpp
        )