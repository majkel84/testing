#include "bowlingLane.hpp"

#include <memory>
#include <iostream>

BowlingLane::BowlingLane() {}

BowlingLane::BowlingLane(File file) {
    file = File(name_);
}

void BowlingLane::setPlayer(std::string name, std::vector<std::pair<int, int>> points) {
    std::unique_ptr<Player> player
            = std::make_unique<Player>(name, points);
    players_.emplace_back(std::move(player));
}

void BowlingLane::showResult() {
    std::cout << BowlingLane::printResultToScreen();
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

std::string BowlingLane::printResultToScreen() {
    std::string result = convertEnumToString() +'\n';
    for (const auto& it : players_) {
        result += it->getInfo();
    }
    return result;
}
