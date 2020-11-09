#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "bowlingLane.hpp"

struct TestBowlingLine : public ::testing::Test {
    BowlingLane bl = BowlingLane();
    std::string results{};
    std::vector<std::pair<int, int>> points{{1, 1}, {1, 2}};
};

TEST_F(TestBowlingLine, checkIfSetPlayerAddPlayer) {
    bl.setPlayer("player", points);
    EXPECT_TRUE(bl.checkGameStatus());
    
    bl.checkGameStatus();
    EXPECT_EQ(bl.convertEnumToString(), "In Progress ");
}

TEST_F(TestBowlingLine, checkPrintResultToScreen) {
    bl.setPlayer("player", points);
    bl.checkGameStatus();
    EXPECT_EQ(bl.getResult(), "In Progress Name: player Score: 5");
}
