#pragma once
#include <vector>

class Game {
public:
    void checkGameProgress(std::vector<std::pair<int, int>> score);
    bool getIsFinished() const;
    static void printHelp();

private:
    bool isFinished_;
};
