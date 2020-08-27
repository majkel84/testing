#pragma once

#include <memory>
#include <string>
#include <vector>

#include "file.hpp"
#include "player.hpp"

enum class gameStatus {
    NoGame,
    InProgress,
    Finish
};

class BowlingLane {
public:
    BowlingLane();
    BowlingLane(File file);
    void setPlayer(std::string name, std::vector<std::pair<int, int>> points);
    void showResult();
    void checkGameStatus();
    std::string convertEnumToString();
    std::string printResultToScreen();

private:
    gameStatus status_;
    std::string name_;
    std::unique_ptr<File> file_;
    std::vector<std::unique_ptr<Player>> players_;
};
