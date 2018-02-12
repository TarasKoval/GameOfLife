#ifndef MAINGAME_GAME_H
#define MAINGAME_GAME_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstring>

class Game {
    static const int height = 40;
    static const int width = 40;

    char currentBoard[height][width];
    char tempBoard[height][width];

    bool loadPattern();

    void initBoards();

    int validateIntInput();

    char validateCharInput();

    void startSimulation();

    void nextGeneration();

    int neighbours(int x, int y);

public:
    Game();

    ~Game();

    Game(const Game &) = delete;

    Game &operator=(const Game &) = delete;

    void showMenu();

    void outputToConsole();

    void outputToFile(const std::string &path);

    void startSimulation(int numberOfGenerations);

    bool loadFile(const std::string &path);
};

#endif //MAINGAME_GAME_H
