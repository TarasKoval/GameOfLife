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
public:
    Game() { printBack(); }

    ~Game() {}

    void loadPattern() {
        int input = 0;
        do {
            std::cout << "\n\n\n\nChose pattern\n";
            std::cout << "(1) Glider\n";
            std::cout << "(2) Pulsar (period 3)\n";
            std::cout << "(3) Glider gun\n";

            input = validateIntInput();

            if (input == 1) loadFile("../resources/glider.txt");
            else if (input == 2) loadFile("../resources/pulsar.txt");
            else loadFile("../resources/gliderGun.txt");

        } while (input < 1 || input > 3);
    }

    void printBack() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                currentBoard[i][j] = '.';
                tempBoard[i][j] = '.';
            }
        }
    }

    void print() {

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++)
                std::cout << currentBoard[i][j] << ' ';
            std::cout << std::endl;

        }
    }

    int validateIntInput() {
        int tempInput;
        std::cin >> tempInput;
        while (std::cin.fail()) {
            std::cout << "Enter choice again: ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> tempInput;
        }
        return tempInput;
    }

    char validateCharInput() {
        std::string tempInput;
        std::cin >> tempInput;
        while (!isalpha(tempInput[0]) || (tempInput.size() > 1)) {
            std::cout << "Enter choice again: ";
            std::cin >> tempInput;
        }
        return tempInput[0];
    }

    //int number of gens, bool printEveryGeneration
    void startGen() {
        int numberOfGenerations = 0;
        char answer;
        do {

            do {
                std::cout << "How many generations would you like to simulate? ";
                numberOfGenerations = validateIntInput();
            } while (numberOfGenerations < 0);


            for (int i = 0; i < numberOfGenerations; i++) {
                nextGen();
                std::cout << "\n\n\n\n\n";
                print();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            do {
                std::cout << "Do you want to continue simulation? (y/n)";
                answer = validateCharInput();
            } while (answer != 'y' && answer != 'n');


        } while (answer == 'y');
    }

    void showMenu() {
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
                printBack();
                loadPattern();
                print();
                startGen();
            } else if (input == 2) {
                printBack();
                std::string path;
                std::cout << "input path to the file: ";
                std::cin >> path;
                if (loadFile(path)) {
                    print();
                    startGen();
                }
            }

        } while (input != 3);
        std::cout << "Bye";
    }

    int neighbours(int x, int y) {
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

    void nextGen() {
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

    bool loadFile(const std::string &path) {
        std::string str;
        std::ifstream myReadFile(path);
        if (!myReadFile) {
            std::cout << "wrong address to the file" << std::endl;
            return false;
        }

        int tempHeight = 0;
        while (getline(myReadFile, str)) {
//            std::cout << str << std::endl;
            for (int i = 0; i < width; i++) {
                currentBoard[tempHeight][i] = str[i];
            }
            tempHeight++;
        }
        myReadFile.close();
        return true;
//        print();
//        startGen();

    }
};

int main() {
    Game mainGame;
    mainGame.showMenu();

    return 0;
}
