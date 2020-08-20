#include "player.hpp"

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
