#include "player.hpp"

#include <iomanip>
#include <iterator>
#include <sstream>

Player::Player() {}

Player::Player(std::string name, std::vector<std::pair<int, int>> points)
    : name_(name),
      points_(points)
{}

std::string Player::getName() const {
    return name_;
}

int Player::getScore() const {
    return score_;
}

void Player::setScore(int score) {
    score_ = score;
}

void Player::countScore(std::vector<std::pair<int, int>> score) {
    int result = 0;
    int lastNormalRound = 9;

    for (int i = 0; i <= lastNormalRound; i++) {
        if (score[i].first == 10) {
            if (score[i + 1].first == 10) {
                result += (score[i].first + score[i + 1].first + score[i + 2].first);
            } else {
                result += (score[i].first + score[i + 1].first + score[i + 1].second);
            }
            continue;
        }

        if ((score[i].first + score[i].second == 10) && (score[i].first != 10)) {
            result += (score[i].first + score[i].second + score[i + 1].first);
            continue;
        }

        result += (score[i].first + score[i].second);
    }
    Player::setScore(result);
}

void Player::setPoints(std::vector<std::pair<int, int> > points) {
    points_ = points;
}

int Player::getPointsSize() {
    return points_.size();
}

int Player::getPointsElem(int elem) {
    return points_.at(elem).first;
}

std::string Player::getInfo() {
    auto ss = std::stringstream{};
    ss << std::left << std::setw(10) << "Name: " << getName()
       << std::left << std::setw(5) << "\nPoints:\n" << translateVectorToString()
       << std::left << std::setw(5) << "\nScore: " << getScore() << '\n';
    return ss.str();
}

std::string Player::translateVectorToString() {
    std::string stringPoints = name_ + ": ";
    for (const auto& it : points_) {
        if (it.first == 10) {
            stringPoints += "X|";
        }
        else if (it.first + it.second == 10) {
            stringPoints += it.first;
            stringPoints += "-|";
        }
        else if (it.first + it.second < 10) {
            stringPoints += it.first;
            stringPoints += it.second;
            stringPoints += "|";
        }
    }
    return stringPoints;
}
