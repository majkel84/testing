#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "bowlingLane.hpp"
#include "file.hpp"

struct TestBowlingLine : public ::testing::Test {
    File file = File("../lane.txt");
    BowlingLane bl = BowlingLane(file);
    std::string results{};
    std::vector<std::pair<int, int>> points {};
};

TEST_F(TestBowlingLine, checkIfSetPlayerAddPlayer) {
    bl.setPlayer();
    results = bl.convertEnumToString();
    EXPECT_TRUE(results == "In Progress");
}

TEST_F(TestBowlingLine, checkPrintResultToScreen) {
    std::vector<std::pair<int, int>> points = {{1, 1}, {1, 2}};
    Player p = Player("player", points);
    p.countScore(points);
    bl.setPlayer();
    results = bl.printResultToScreen();
    EXPECT_TRUE(results == "In Progress\nplayer 5");
}
