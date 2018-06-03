#include <iostream>
#include "../headers/Game.h"
#include "../headers/functions.h"

int main() {

    tests();

    std::cout << "\nFast Simulation\n";
    Game simulation;
    simulation.loadFile("../resources/gliderGun.txt");
    simulation.startSimulation(1050);
    simulation.outputToConsole();

    std::cout << "\nMain Menu\n";
    Game menu;
    menu.showMenu();

    return 0;
}
