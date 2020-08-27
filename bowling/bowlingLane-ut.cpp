#include <gtest/gtest.h>
#include <string>

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
