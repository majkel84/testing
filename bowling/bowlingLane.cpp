#include "bowlingLane.hpp"

#include <iostream>

BowlingLane::BowlingLane(File file) {
    file = File(name_);
}

void BowlingLane::showResult() {
    BowlingLane::printResultToScreen();
}

void BowlingLane::printResultToScreen() {
    for (const auto& it : players_) {
        std::cout << it->getScore();
    }
}
