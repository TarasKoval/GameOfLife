#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

class Game {
    static const int height = 40;
    static const int width = 40;

    char currentBoard[height][width];
    char tempBoard[height][width];
public:
    Game() {}

    ~Game() {}

    void loadPattern() {
        int input = 0;
        do {
            std::cout << "\n\n\n\nChose pattern\n";
            std::cout << "(1) Glider\n";
            std::cout << "(2) Pulsar (period 3)\n";
            std::cout << "(3) Glider gun\n";

            std::cin >> input;

            if (input == 1) gliderPattern();
            else if (input == 2) pulsarPattern();
            else gliderGunPattern();

        } while (input < 1 || input > 3);
    }

    void back() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                currentBoard[i][j] = '.';
                tempBoard[i][j] = '.';
            }
        }
    }

    void loadFile() {
        /*
         * back();

        std::string str;
        std::ifstream myReadFile("/home/antares/CLionProjects/GameOfLife/game1/file.txt");
        if (!myReadFile) {
            std::cout << "wrong address to the file" << std::endl;
            return;
        }

        while (getline(myReadFile, str)) {
            {



                std::cout << str << std::endl;


            }
        }
        myReadFile.close();
         */
        std::cout << "load file";

    }

    void gliderPattern() {
        back();

        currentBoard[0][1] = '0';
        currentBoard[1][2] = '0';
        currentBoard[2][0] = '0';
        currentBoard[2][1] = '0';
        currentBoard[2][2] = '0';

        printBoard();
        callNextGen();

    }

    void pulsarPattern() {
        back();

        currentBoard[2][4] = '0';
        currentBoard[2][5] = '0';
        currentBoard[2][6] = '0';
        currentBoard[2][10] = '0';
        currentBoard[2][11] = '0';
        currentBoard[2][12] = '0';

        currentBoard[4][2] = '0';
        currentBoard[4][7] = '0';
        currentBoard[4][9] = '0';
        currentBoard[4][14] = '0';

        currentBoard[5][2] = '0';
        currentBoard[5][7] = '0';
        currentBoard[5][9] = '0';
        currentBoard[5][14] = '0';

        currentBoard[6][2] = '0';
        currentBoard[6][7] = '0';
        currentBoard[6][9] = '0';
        currentBoard[6][14] = '0';

        currentBoard[7][4] = '0';
        currentBoard[7][5] = '0';
        currentBoard[7][6] = '0';
        currentBoard[7][10] = '0';
        currentBoard[7][11] = '0';
        currentBoard[7][12] = '0';

        currentBoard[9][4] = '0';
        currentBoard[9][5] = '0';
        currentBoard[9][6] = '0';
        currentBoard[9][10] = '0';
        currentBoard[9][11] = '0';
        currentBoard[9][12] = '0';

        currentBoard[10][2] = '0';
        currentBoard[10][7] = '0';
        currentBoard[10][9] = '0';
        currentBoard[10][14] = '0';

        currentBoard[11][2] = '0';
        currentBoard[11][7] = '0';
        currentBoard[11][9] = '0';
        currentBoard[11][14] = '0';

        currentBoard[12][2] = '0';
        currentBoard[12][7] = '0';
        currentBoard[12][9] = '0';
        currentBoard[12][14] = '0';

        currentBoard[14][4] = '0';
        currentBoard[14][5] = '0';
        currentBoard[14][6] = '0';
        currentBoard[14][10] = '0';
        currentBoard[14][11] = '0';
        currentBoard[14][12] = '0';

        printBoard();
    }

    void gliderGunPattern() {
        back();

        currentBoard[5][1] = '0';
        currentBoard[6][1] = '0';
        currentBoard[5][2] = '0';
        currentBoard[6][2] = '0';

        currentBoard[5][11] = '0';
        currentBoard[6][11] = '0';
        currentBoard[7][11] = '0';
        currentBoard[4][12] = '0';
        currentBoard[8][12] = '0';
        currentBoard[3][13] = '0';
        currentBoard[9][13] = '0';
        currentBoard[3][14] = '0';
        currentBoard[9][14] = '0';
        currentBoard[6][15] = '0';
        currentBoard[4][16] = '0';
        currentBoard[8][16] = '0';
        currentBoard[5][17] = '0';
        currentBoard[6][17] = '0';
        currentBoard[7][17] = '0';
        currentBoard[6][18] = '0';

        currentBoard[3][21] = '0';
        currentBoard[4][21] = '0';
        currentBoard[5][21] = '0';
        currentBoard[3][22] = '0';
        currentBoard[4][22] = '0';
        currentBoard[5][22] = '0';
        currentBoard[2][23] = '0';
        currentBoard[6][23] = '0';
        currentBoard[1][25] = '0';
        currentBoard[2][25] = '0';
        currentBoard[6][25] = '0';
        currentBoard[7][25] = '0';

        currentBoard[3][35] = '0';
        currentBoard[4][35] = '0';
        currentBoard[3][36] = '0';
        currentBoard[4][36] = '0';

        printBoard();
    }

    void printBoard() {

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++)
                std::cout << currentBoard[i][j] << ' ';
            std::cout << std::endl;

        }
    }

    void showMenu() {
        int input = 0;
        do {
            do {
                std::cout << "\n\n\n\nMenu\n";
                std::cout << "(1) Start game with pattern\n";
                std::cout << "(2) Start game with file\n";
                std::cout << "(3) Exit\n";
                std::cin >> input;
            } while (input < 1 || input > 3);

            if (input == 1) loadPattern();
            else if (input == 2) loadFile();
            else return;

        } while (input != 3);
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

    void callNextGen() {
        int number = 50;
        for (int i = 0; i < number; i++) {
            nextGen();
        }
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
        copyDataToCurrentGrid();
        std::cout << "\n\n\n\n\n";
        printBoard();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
    }

    void copyDataToCurrentGrid() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                currentBoard[i][j] = tempBoard[i][j];
            }
        }
    }
};

int main() {
    Game mainGame;
    mainGame.showMenu();

    return 0;
}
