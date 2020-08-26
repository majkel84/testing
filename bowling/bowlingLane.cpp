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

void BowlingLane::checkGameStatus() {
    if (players_.empty()) {
        status_ = gameStatus::NoGame;
    }
    else if (players_.at(0)->getPointsSize() ==10
            && players_.at(0)->getPointsElem(9) != 10) {
        status_ = gameStatus::Finish;
    }
    else if (players_.at(0)->getPointsSize() ==11 && players_.at(0)->getPointsElem(9) != 10) {
        status_ = gameStatus::Finish;
    }
    status_ = gameStatus::InProgress;
}

std::string BowlingLane::convertEnumToString() {
    if (status_ == gameStatus::Finish) {
        return "Finished";
    }
    else if (status_ == gameStatus::InProgress) {
        return "In Progress";
    }
    return "No game";
}

void BowlingLane::printResultToScreen() {
    for (const auto& it : players_) {
        std::cout << it->getInfo();
    }
}
