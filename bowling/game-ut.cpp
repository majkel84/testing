#include <gtest/gtest.h>

#include "game.hpp"
#include <vector>

struct TestGame : public ::testing::Test {
    Game game;
    std::vector<std::pair<int, int>> score{};
};

TEST_F(TestGame, checkIfGameInProgressIsFinished) {
    score = {{1, 5}, {2, 5}, {4, 5}, {1, 3}};
    game.checkGameProgress(score);
    ASSERT_EQ(game.getIsFinished(), false);
}

TEST_F(TestGame, checkIfGameWithoutStrikesAndSparesIsFinished) {
    score = {{1, 5}, {2, 5}, {4, 5}, {1, 3}, {9, 0}, {5, 4}, {4, 4}, {1, 5}, {0, 5}, {0, 9}};
    game.checkGameProgress(score);
    ASSERT_EQ(game.getIsFinished(), true);
}

TEST_F(TestGame, checkIfGameWithSpareAtTheEndIsFinished) {
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {3, 7}, {1, 0}};
    game.checkGameProgress(score);
    ASSERT_EQ(game.getIsFinished(), true);
}

TEST_F(TestGame, checkIfGameWithSpareAtTheEndIsNotFinished) {
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {3, 7}};
    game.checkGameProgress(score);
    ASSERT_EQ(game.getIsFinished(), false);
}

TEST_F(TestGame, checkIfGameWithStrikesAtTheEndIsFinished) {
    score = {{10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0},
             {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}};
    game.checkGameProgress(score);
    ASSERT_EQ(game.getIsFinished(), true);
}

TEST_F(TestGame, checkIfGameWithStrikesAtTheEndIsNotFinished) {
    score = {{10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}};
    game.checkGameProgress(score);
    ASSERT_EQ(game.getIsFinished(), false);
}

TEST_F(TestGame, checkIfMixedGameIsFinished) {
    score = {{10, 0}, {7, 3}, {9, 0}, {10, 0}, {0, 8}, {8, 2}, {0, 6}, {10, 0}, {10, 0}, {10, 0}, {8, 1}};
    game.checkGameProgress(score);
    ASSERT_EQ(game.getIsFinished(), true);
}
