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

TEST_F(TestPlayer, checkScoreGameWithoutSpareAndStrike) {
    score = {{1, 5}, {2, 5}, {4, 5}, {1, 3}, {9, 0}, {5, 4}, {4, 4}, {1, 5}, {0, 5}, {0, 9}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 72);
}

TEST_F(TestPlayer, checkScoreGameWithStrikeInTheMiddle) {
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {10, 0}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 30);
}

TEST_F(TestPlayer, checkScoreGameWithSpareInTheMiddle) {
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {5, 5}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 29);
}

TEST_F(TestPlayer, checkScoreGameWithStrikeAtTheEnd) {
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {10, 0}, {1, 1}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 30);
}

TEST_F(TestPlayer, checkScoreGameWithSpareAtTheEnd) {
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {5, 5}, {1, 0}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 29);
}

TEST_F(TestPlayer, checkScoreGameWithAllStrikes) {
    score = {{10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0},
             {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 300);
}

TEST_F(TestPlayer, checkScoreGameWithAllSpares) {
    score = {{5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 0}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 150);
}

TEST_F(TestPlayer, checkScoreGameWithSpareAndStrikeInTheMiddle) {
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {5, 5}, {1, 1}, {10, 0}, {1, 1}, {1, 1}, {1, 1}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 39);
}

TEST_F(TestPlayer, checkScoreGameWithOneSpareAfterStrikeInTheMiddle) {
    score = {{1, 1}, {1, 1}, {1, 1}, {10, 0}, {5, 5}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 47);
}

TEST_F(TestPlayer, checkScoreGameWithTwoSparesAfterStrikeInTheMiddle) {
    score = {{1, 1}, {1, 1}, {1, 1}, {10, 0}, {5, 5}, {5, 5}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 60);
}

TEST_F(TestPlayer, checkScoreGameWithOneStrikeAfterSpareInTheMiddle) {
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {5, 5}, {10, 0}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 48);
}

TEST_F(TestPlayer, checkScoreGameWithTwoStrikesAfterSpareInTheMiddle) {
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {5, 5}, {10, 0}, {10, 0}, {1, 1}, {1, 1}, {1, 1}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 67);
}

TEST_F(TestPlayer, checkScoreGameWithStrikesOnlyInLastRound) {
    score = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {10, 0}, {10, 0}, {10, 0}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 30);
}

TEST_F(TestPlayer, checkScoreGameWithNoStrikeAndNoSpareInLastRound) {
    score = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {4, 4}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 8);
}

TEST_F(TestPlayer, checkScoreGameWithMixedStrikesAndSpares) {
    score = {{5, 5}, {10, 0}, {5, 5}, {10, 0}, {5, 5}, {10, 0}, {5, 5}, {10, 0}, {5, 5}, {10, 0}, {5, 5}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 200);
}
