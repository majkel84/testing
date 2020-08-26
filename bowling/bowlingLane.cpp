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
    if (players_.empty()) {
        return gameStatus::NoGame;
    }
    else if (players_.at(0)->getPointsSize() ==10
            && players_.at(0)->getPointsElem(9) != 10) {
        return gameStatus::Finish;
    }
    else if (players_.at(0)->getPointsSize() ==11 && players_.at(0)->getPointsElem(9) != 10) {
        return gameStatus::Finish;
    }
    return gameStatus::InProgress;
}

void BowlingLane::printResultToScreen() {
    for (const auto& it : players_) {
        std::cout << it->getInfo();
    }
}
