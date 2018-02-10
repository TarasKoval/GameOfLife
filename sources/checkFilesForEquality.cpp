#include "../headers/checkFilesForEquality.h"

bool checkFilesForEquality(const std::string &path1, const std::string &path2) {
    std::fstream f1, f2;
    char char1, char2;
    bool equality = true;

    f1.open(path1, std::ios::in);
    if (!f1) {
        std::cerr << "File can't be opened" << std::endl;
        exit(1);
    }

    f2.open(path2, std::ios::in);
    if (!f2) {
        std::cerr << "File can't be opened" << std::endl;
        exit(2);
    }

    while (true) {
        char1 = static_cast<char>(f1.get());
        char2 = static_cast<char>(f2.get());
        if (char1 != char2) {
            equality = false;
            break;
        }
        if ((char1 == EOF) || (char2 == EOF))
            break;
    }
    f1.close();
    f2.close();

    return equality;
}
