#include "bowlingLane.hpp"

#include <memory>
#include <iostream>

BowlingLane::BowlingLane(File file) {
    file = File(name_);
}

void BowlingLane::setPlayer() {
    std::unique_ptr<Player> player
            = std::make_unique<Player>("name", file_->getScores());
    players_.emplace_back(std::move(player));
}

void BowlingLane::showResult() {
    BowlingLane::printResultToScreen();
}

gameStatus BowlingLane::checkGameStatus() {
    gameStatus gs;
    /*if (players_.at(0)->points_.size() ==10); {

    }*/
    return gs;
}

void BowlingLane::printResultToScreen() {
    for (const auto& it : players_) {
        std::cout << it->getInfo();
    }
}
