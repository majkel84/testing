#include "player.hpp"

int Player::getScore() const {
    return score_;
}

void Player::setScore(int score) {
    score_ = score;
}

int Player::countScore(std::vector<std::pair<int, int>> score) {
    int result = 0;
    for (const auto& it : score) {
        result += it.first;
        result += it.second;
    }
    Player::setScore(result);
}
