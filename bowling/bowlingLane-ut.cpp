#include <gtest/gtest.h>

#include "bowlingLane.hpp"

struct TestBowlingLine : public ::testing::Test {
    BowlingLane bl;
    std::string results{};
    std::vector<std::pair<int, int>> points {};
};

/*TEST_F(TestBowlingLine, checkIfGameInProgressIsTranslatedCorrectly) {
    results = "15|25|45|13|";
    score = {{1, 5}, {2, 5}, {4, 5}, {1, 3}};
    file.translateResultsToScoreVector(results);
    ASSERT_EQ(file.getScores(), score);
}*/
