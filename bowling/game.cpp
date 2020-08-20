#include "game.hpp"

#include <iostream>

void Game::printHelp(){
    std::cout << "This is simple application which count points in Bowling Game \n"
        << "Program takes two parameters:\n"
        << "1. Is directory which includes txt files with game state"
        << " on bowling lanes\n"
        << "2.(optional) Is optional output file where processed results is saved\n"
        << "If you don't give second parameter, results has been printed to screen\n"
        << "Example of use: \n"
        << "***** ./bowling inputDirectory results.txt\n"
        << "***** ./bowling inputDirectory";

}
