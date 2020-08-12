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
private:
    gameStatus status_;
    std::string name_;
    std::unique_ptr<File> file_;
    std::vector<std::unique_ptr<Player>> players_;
};
