#pragma once
#include <vector>
#include <string>

#include "game.hpp"

class Player {
public:
    std::string getName() const;
    int getScore() const;
    void setScore(int score);
    void countScore(std::vector<std::pair<int, int>> score);

private:
    std::string name_;
    int score_;
};
