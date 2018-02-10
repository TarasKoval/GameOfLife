#include "../headers/checkFilesForEquality.h"

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
