#include "../include/functions.h"

bool checkFilesForEquality(const std::string &path1, const std::string &path2) {
    std::fstream stream1, stream2;
    char char1, char2;
    bool equality = true;

    stream1.open(path1, std::ios::in);
    if (!stream1) {
        std::cerr << "File can't be opened" << std::endl;
        exit(1);
    }

    stream2.open(path2, std::ios::in);
    if (!stream2) {
        std::cerr << "File can't be opened" << std::endl;
        exit(2);
    }

    while (true) {
        char1 = static_cast<char>(stream1.get());
        char2 = static_cast<char>(stream2.get());
        if (char1 != char2) {
            equality = false;
            break;
        }
        if ((char1 == EOF) || (char2 == EOF))
            break;
    }
    stream1.close();
    stream2.close();

    return equality;
}

void tests() {
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

    //delete temp file
    if (remove("../resources/temp.txt") != 0) {
        std::cerr << "Error deleting file" << std::endl;
        exit(3);
    }

    if (allTestsPassed) {
        std::cout << "All Tests Passed" << std::endl;
    } else {
        std::cout << "Tests failed" << std::endl;
    }
}
