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
    std::string inputDirectory;
    std::string outputFile;
    Game game;
    if (argc == 1) {
        std::cout << "You haven't specified the path to the input files\n";
        return EXIT_FAILURE;
    } else if (argc == 2 && std::string(argv[1]) == "--help"
        || argc == 2 && std::string(argv[1]) == "--h") {
        oneParameter(argv[1]);
        return EXIT_SUCCESS;
    } else if (argc == 3) {
        inputDirectory = argv[1];
        outputFile = argv[2];
        return EXIT_SUCCESS;
    } else if (argc >= 4) {
        std::cout << "Too many arguments\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
