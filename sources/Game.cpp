#include "../headers/Game.h"

Game::Game() {}

Game::~Game() {}

void Game::loadPattern() {
    int input = 0;
    do {
        std::cout << "\n\n\n\nChose pattern\n";
        std::cout << "(1) Glider\n";
        std::cout << "(2) Pulsar (period 3)\n";
        std::cout << "(3) Glider gun\n";
        std::cout << "(4) Blinker Toad Beacon\n";

        input = validateIntInput();

        if (input == 1) loadFile("../resources/glider.txt");
        else if (input == 2) loadFile("../resources/pulsar.txt");
        else if (input == 3) loadFile("../resources/gliderGun.txt");
        else if (input == 4) loadFile("../resources/blinkerToadBeacon.txt");

    } while (input < 1 || input > 4);
}

void Game::printBack() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            currentBoard[i][j] = '.';
            tempBoard[i][j] = '.';
        }
    }
}

int Game::validateIntInput() {
    int tempInput;
    std::cin >> tempInput;
    while (std::cin.fail() || tempInput < 0) {
        std::cout << "Enter choice again: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> tempInput;
    }
    return tempInput;
}

char Game::validateCharInput() {
    std::string tempInput;
    std::cin >> tempInput;
    while (!isalpha(tempInput[0]) || (tempInput.size() > 1)) {
        std::cout << "Enter choice again: ";
        std::cin >> tempInput;
    }
    return tempInput[0];
}

void Game::startSimulation() {
    int numberOfGenerations;
    char answer;
    do {

        std::cout << "How many generations would you like to simulate? ";
        numberOfGenerations = validateIntInput();


        for (int i = 0; i < numberOfGenerations; i++) {
            nextGen();
            std::cout << "\n\n\n\n\n";
            outputToConsole();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        do {
            std::cout << "Do you want to continue simulation? (y/n)";
            answer = validateCharInput();
        } while (answer != 'y' && answer != 'n');


    } while (answer == 'y');
}

void Game::nextGen() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (currentBoard[i][j] == '0') {
                if (neighbours(i, j) < 2) {
                    tempBoard[i][j] = '.';
                } else if (neighbours(i, j) > 3) {
                    tempBoard[i][j] = '.';

                } else {
                    tempBoard[i][j] = '0';

                }
            } else {
                if (neighbours(i, j) == 3) {
                    tempBoard[i][j] = '0';

                } else {
                    tempBoard[i][j] = '.';

                }
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            currentBoard[i][j] = tempBoard[i][j];
        }
    }

}

int Game::neighbours(int x, int y) {
    int count = 0;

    if (currentBoard[x - 1][y - 1] == '0') {
        count += 1;
    }
    if (currentBoard[x - 1][y] == '0') {
        count += 1;
    }
    if (currentBoard[x - 1][y + 1] == '0') {
        count += 1;
    }
    if (currentBoard[x][y - 1] == '0') {
        count += 1;
    }
    if (currentBoard[x][y + 1] == '0') {
        count += 1;
    }
    if (currentBoard[x + 1][y - 1] == '0') {
        count += 1;
    }
    if (currentBoard[x + 1][y] == '0') {
        count += 1;
    }
    if (currentBoard[x + 1][y + 1] == '0') {
        count += 1;
    }

    return count;
}

void Game::showMenu() {
    int input = 0;
    do {
        do {
            std::cout << "\n\n\n\nMenu\n";
            std::cout << "(1) Start game with pattern\n";
            std::cout << "(2) Start game with file\n";
            std::cout << "(3) Exit\n";
            input = validateIntInput();
        } while (input < 1 || input > 3);

        if (input == 1) {
            loadPattern();
            outputToConsole();
            startSimulation();
        } else if (input == 2) {
            std::string path;
            std::cout << "input path to the file: ";
            std::cin >> path;
            if (loadFile(path)) {
                outputToConsole();
                startSimulation();
            }
        }

    } while (input != 3);
    std::cout << "Bye" << std::endl;
}

void Game::outputToConsole() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << currentBoard[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void Game::outputToFile(const std::string &path) {
    std::ofstream stream;

    stream.open(path);
    if (!stream)
        std::cout << "Opening file failed" << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            stream << currentBoard[i][j];
        }
        //doesn't write to file last empty line
        if (i == height - 1) {
            continue;
        }
        stream << std::endl;
    }
    stream.close();
}

void Game::startSimulation(int numberOfGens) {
    if (numberOfGens < 0) {
        std::cout << "number of generations have to be >=0";
        return;
    }

    for (int i = 0; i < numberOfGens; i++) {
        nextGen();
    }
}

bool Game::loadFile(const std::string &path) {
    printBack();
    std::string str;
    std::ifstream myReadFile(path);
    if (!myReadFile) {
        std::cout << "wrong address to the file" << std::endl;
        return false;
    }

    int tempHeight = 0;
    while (getline(myReadFile, str)) {
        for (int i = 0; (i < str.length()) && (i < width); i++) {
            if (str[i] != '.' && str[i] != '0') {
                currentBoard[tempHeight][i] = '.';
            } else {
                currentBoard[tempHeight][i] = str[i];
            }
        }

        tempHeight++;
    }
    myReadFile.close();
    return true;
}