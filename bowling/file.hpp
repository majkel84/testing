#pragma once

#include <string>
#include <vector>

const char delimiter = '|';

class File {
public:
    File(std::string fileName);
    std::vector<std::pair<int, int>> getScores() const;
    std::string getResults() const;
    void translateResultsToScoreVector(std::string results);
    void readFile();
    void saveFile();

private:
    std::string fileName_;
    std::string results_;
    std::vector<std::pair<int, int>> score_;
    void splitString(const std::string& str, std::vector<std::string>& vec);
};
