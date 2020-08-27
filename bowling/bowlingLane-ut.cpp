#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "bowlingLane.hpp"
#include "file.hpp"

struct TestBowlingLine : public ::testing::Test {
    BowlingLane bl = BowlingLane();
    std::string results{};
    std::vector<std::pair<int, int>> points {{1, 1}, {1, 2}};
};

TEST_F(TestBowlingLine, checkIfSetPlayerAddPlayer) {
    bl.setPlayer("player", points);
    bl.checkGameStatus();
    results = bl.convertEnumToString();
    EXPECT_TRUE(results == "In Progress");
}

TEST_F(TestBowlingLine, checkPrintResultToScreen) {
    Player p = Player("player", points);
    p.countScore(points);
    bl.setPlayer("player", points);
    results = bl.printResultToScreen();
    EXPECT_TRUE(results == "In Progress\nplayer 5");
}
