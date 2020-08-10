#pragma once
#include <vector>

class Player {
public:
    int getScore() const;
    void setScore(int score);

    void countScore(std::vector<std::pair<int, int>> score);

private:
    int score_;
};
