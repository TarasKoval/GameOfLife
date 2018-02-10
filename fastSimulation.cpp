#include <iostream>
#include "headers/Game.h"

int main() {
    Game mainGame;
    mainGame.loadFile("../resources/gliderGun.txt");
    mainGame.startSimulation(1050);
    mainGame.outputToConsole();

    return 0;
}
