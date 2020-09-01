#include <iostream>
#include <string>

#include "game.hpp"

void oneParameter(const std::string& param) {
    if (param.front() == '-') {
        if (param == "-h" || param == "--help") {
            Game::printHelp();
            return;
        } else {
            std::cout << "Unknown parameter: " << param << '\n';
            return;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "You haven't specified the path to the input files\n";
        return EXIT_FAILURE;
    } else if (argc >= 4) {
        std::cout << "Too many arguments\n";
        return EXIT_FAILURE;
    } else if (argc == 2) {
        oneParameter(argv[1]);
        return EXIT_SUCCESS;
    }

    return EXIT_SUCCESS;
}
