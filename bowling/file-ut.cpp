#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "file.hpp"

struct TestFile : public ::testing::Test {
    File file = File("../lane.txt");
    std::map<std::string, std::vector<std::pair<int, int>>> playerResults_;
    std::string results{};
    std::vector<std::string> file_contents{};
    std::vector<std::pair<int, int>> score{};
};

TEST_F(TestFile, checkIfGameInProgressIsTranslatedCorrectly) {
    results = "15|25|45|13|";
    score = {{1, 5}, {2, 5}, {4, 5}, {1, 3}};
    std::vector<std::pair<int, int>> scoreToCheck = file.translateResultsToScoreVector(results);
    ASSERT_EQ(scoreToCheck, score);
}

TEST_F(TestFile, checkIfGameWithNoStrikeOrSpareIsTranslatedCorrectly) {
    results = "15|25|45|13|9-|54|44|15|-5|-9|";
    score = {{1, 5}, {2, 5}, {4, 5}, {1, 3}, {9, 0}, {5, 4}, {4, 4}, {1, 5}, {0, 5}, {0, 9}};
    std::vector<std::pair<int, int>> scoreToCheck = file.translateResultsToScoreVector(results);
    ASSERT_EQ(scoreToCheck, score);
}

TEST_F(TestFile, checkIfGameWithSpareAtTheEndIsTranslatedCorrectly) {
    results = "11|11|11|11|11|11|11|11|11|37||1";
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {3, 7}, {1, 0}};
    std::vector<std::pair<int, int>> scoreToCheck = file.translateResultsToScoreVector(results);
    ASSERT_EQ(scoreToCheck, score);
}

TEST_F(TestFile, checkIfGameOfAllStrikesIsTranslatedCorrectly) {
    results = "X|X|X|X|X|X|X|X|X|X||XX";
    score = {{10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0},
             {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}};
    std::vector<std::pair<int, int>> scoreToCheck = file.translateResultsToScoreVector(results);
    ASSERT_EQ(scoreToCheck, score);
}

TEST_F(TestFile, checkIfGameOfMixedThrowsIsTranslatedCorrectly) {
    results = "X|7/|9-|X|-8|8/|-6|X|X|X||81";
    score = {{10, 0}, {7, 3}, {9, 0}, {10, 0}, {0, 8}, {8, 2}, {0, 6}, {10, 0}, {10, 0}, {10, 0}, {8, 1}};
    std::vector<std::pair<int, int>> scoreToCheck = file.translateResultsToScoreVector(results);
    ASSERT_EQ(scoreToCheck, score);
}

TEST_F(TestFile, checkIfMultilaneFileIsReadCorrectly) {
    file_contents = {"Name1:X|4-|3", "Name2:34|X|0-", ":X|22|33"};
    File file1 = File("../lane_multi.txt");
    file1.readFile();
    playerResults_ = file1.getPlayerResults();
    std::vector<std::pair<int, int>> result = file1.translateResultsToScoreVector("X|4-|3");
    ASSERT_EQ(playerResults_["Name1"], result);
    result = file1.translateResultsToScoreVector("34|X|0-");
    ASSERT_EQ(playerResults_["Name2"], result);
    result = file1.translateResultsToScoreVector("X|22|33");
    ASSERT_EQ(playerResults_[""], result);
}

TEST_F(TestFile, checkSaveGameNoThrow) {
    File file = File("file.txt");
    ASSERT_NO_THROW(file.saveFile());
}
