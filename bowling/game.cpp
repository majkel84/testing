#include "game.hpp"

#include <iostream>

bool Game::getIsFinished() const {
    return isFinished_;
};

void Game::checkGameProgress(std::vector<std::pair<int, int>> score) {
    int lastNormalRound = 9;

    if (score.size() < 10) {
        isFinished_ = false;
    } else if ((score[lastNormalRound].first + score[lastNormalRound].second < 10) && (score.size() == 10)) {
        isFinished_ = true;
    } else if ((score[lastNormalRound].first + score[lastNormalRound].second == 10) &&
               (score[lastNormalRound].first != 10) && (score.size() == 11)) {
        isFinished_ = true;
    } else if ((score[lastNormalRound].first == 10) && (score[lastNormalRound + 1].first != 10) &&
               (score.size() == 11)) {
        isFinished_ = true;
    } else if ((score[lastNormalRound].first == 10) && (score[lastNormalRound + 1].first == 10) &&
               (score.size() == 12)) {
        isFinished_ = true;
    } else {
        isFinished_ = false;
    }
};

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
