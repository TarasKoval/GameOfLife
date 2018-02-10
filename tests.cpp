#include <iostream>
#include "headers/Game.h"
#include "headers/checkFilesForEquality.h"

int main() {
    bool allTestsPassed = true;

    Game mainGame;
    mainGame.loadFile("../resources/glider.txt");
    mainGame.startSimulation(40);
    mainGame.outputToFile("../resources/temp.txt");

    if (checkFilesForEquality("../resources/glider40Gen.txt", "../resources/temp.txt")) {
        std::cout << "First Test Passed" << std::endl;
    } else {
        std::cout << "First Test Failed" << std::endl;
        allTestsPassed = false;
    }

    //clear the file
    std::ofstream ofs;
    ofs.open("../resources/temp.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    mainGame.loadFile("../resources/blinkerToadBeacon.txt");
    mainGame.startSimulation(1);
    mainGame.outputToFile("../resources/temp.txt");

    if (checkFilesForEquality("../resources/blinkerToadBeacon1Gen.txt", "../resources/temp.txt")) {
        std::cout << "Second Test Passed" << std::endl;
    } else {
        std::cout << "Second Test Failed" << std::endl;
        allTestsPassed = false;
    }

    //delete the file
    if (remove("../resources/temp.txt") != 0) {
        std::cerr << "Error deleting file" << std::endl;
        exit(3);
    }

    if (allTestsPassed) {
        std::cout << "\nAll Tests Passed" << std::endl;
    } else {
        std::cout << "\nTests failed" << std::endl;
        return 1;
    }

    return 0;
}
