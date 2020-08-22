#pragma once
#include <vector>

#include "game.hpp"

class Player {
public:
    int getScore() const;
    void setScore(int score);
    void countScore(std::vector<std::pair<int, int>> score);

private:
    int score_;
};
