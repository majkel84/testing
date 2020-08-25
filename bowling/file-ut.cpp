#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "file.hpp"

struct TestFile : public ::testing::Test {
    File file = File("../lane.txt");
    std::string results{};
    std::vector<std::pair<int, int>> score{};
};

TEST_F(TestFile, checkIfGameInProgressIsTranslatedCorrectly) {
    results = "15|25|45|13|";
    score = {{1, 5}, {2, 5}, {4, 5}, {1, 3}};
    file.translateResultsToScoreVector(results);
    ASSERT_EQ(file.getScores(), score);
}

TEST_F(TestFile, checkIfGameWithNoStrikeOrSpareIsTranslatedCorrectly) {
    results = "15|25|45|13|9-|54|44|15|-5|-9|";
    score = {{1, 5}, {2, 5}, {4, 5}, {1, 3}, {9, 0}, {5, 4}, {4, 4}, {1, 5}, {0, 5}, {0, 9}};
    file.translateResultsToScoreVector(results);
    ASSERT_EQ(file.getScores(), score);
}

TEST_F(TestFile, checkIfGameWithSpareAtTheEndIsTranslatedCorrectly) {
    results = "11|11|11|11|11|11|11|11|11|37||1";
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {3, 7}, {1, 0}};
    file.translateResultsToScoreVector(results);
    ASSERT_EQ(file.getScores(), score);
}

TEST_F(TestFile, checkIfGameOfAllStrikesIsTranslatedCorrectly) {
    results = "X|X|X|X|X|X|X|X|X|X||XX";
    score = {{10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0},
             {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}};
    file.translateResultsToScoreVector(results);
    ASSERT_EQ(file.getScores(), score);
}

TEST_F(TestFile, checkIfGameOfMixedThrowsIsTranslatedCorrectly) {
    results = "X|7/|9-|X|-8|8/|-6|X|X|X||81";
    score = {{10, 0}, {7, 3}, {9, 0}, {10, 0}, {0, 8}, {8, 2}, {0, 6}, {10, 0}, {10, 0}, {10, 0}, {8, 1}};
    file.translateResultsToScoreVector(results);
    ASSERT_EQ(file.getScores(), score);
}

TEST_F(TestFile, checkIfFileIsReadCorrectly) {
    results = "X|7/|9-|X|-8|8/|-6|X|X|X||81";
    file.readFile();
    ASSERT_EQ(file.getResults(), results);
}

TEST_F(TestFile, checkSaveGameNoThrow) {
    File file = File("file.txt");
    ASSERT_NO_THROW(file.saveFile());
}
