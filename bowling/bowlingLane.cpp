#include "bowlingLane.hpp"

#include <algorithm>
#include <iostream>
#include <memory>

BowlingLane::BowlingLane() {}

BowlingLane::BowlingLane(File file) {
    file = File(name_);
}

void BowlingLane::setPlayer(std::string name, std::vector<std::pair<int, int>> points) {
    std::unique_ptr<Player> player = std::make_unique<Player>(name, points);
    players_.emplace_back(std::move(player));
    players_.back()->countScore(points);
}

void BowlingLane::showResult() {
    std::cout << BowlingLane::getResult();
}

bool BowlingLane::checkGameStatus() {
    if (players_.empty()) {
        status_ = gameStatus::NoGame;
        return false;
    }
    for (const auto& it: players_) {
        if (it->getPointsSize() == 10 && it->getPointsElem(9) != 10) {
            status_ = gameStatus::Finish;
            return true;
        } else if (it -> getPointsSize() == 11 && players_.at(0)->getPointsElem(9) != 10) {
            status_ = gameStatus::Finish;
            return true;
        }
        status_ = gameStatus::InProgress;
    }
    return true;
}

std::string BowlingLane::convertEnumToString() {
    if (status_ == gameStatus::Finish) {
        return "Finished ";
    } else if (status_ == gameStatus::InProgress) {
        return "In Progress ";
    }
    return "No game ";
}

std::string BowlingLane::getResult() {
    std::string result = convertEnumToString();
    for (const auto& it : players_) {
        result += it->getInfo();
    }
    return result;
}
