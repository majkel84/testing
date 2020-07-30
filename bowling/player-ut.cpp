#include <gtest/gtest.h>
#include <vector>

#include "player.hpp"

struct TestPlayer : public ::testing::Test {
    Player player;
    std::vector<std::pair<int, int>> score {};
};

TEST_F(TestPlayer, checkScoreGameOfAllMisses) {
    for (auto it = 0; it < 10; it++) {
        score.emplace_back(0, 0);
    }
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 0);
}

TEST_F(TestPlayer, checkScoreGameOfAllOnes) {
    for (auto it = 0; it < 10; it++) {
        score.emplace_back(1, 1);
    }
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 20);
}
