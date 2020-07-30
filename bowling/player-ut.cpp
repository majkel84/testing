#include <gtest/gtest.h>

#include "player.hpp"

struct TestPlayer : public ::testing::Test {
    Player player;
};

TEST_F(TestPlayer, checkScoreGameOfAllMisses) {
    ASSERT_EQ(player.getScore(), 0);
}

TEST_F(TestPlayer, checkScoreGameOfAllOnes) {
    ASSERT_EQ(player.getScore(), 20);
}
