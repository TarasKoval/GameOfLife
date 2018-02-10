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

    void loadPattern();

    void printBack();

    int validateIntInput();

    char validateCharInput();

    void startSimulation();

    void nextGen();

    int neighbours(int x, int y);

public:
    Game();

    ~Game();

    void showMenu();

    void outputToConsole();

    void outputToFile(const std::string &path);

    void startSimulation(int numberOfGens);

    bool loadFile(const std::string &path);
};

#endif //MAINGAME_GAME_H
