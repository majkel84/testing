#pragma once

#include <map>
#include <string>
#include <vector>

class File {
public:
    File(std::string fileName);
    std::map<std::string, std::vector<std::pair<int, int>>> getPlayerResults() const;

    std::vector<std::pair<int, int>> translateResultsToScoreVector(const std::string& results);
    void readFile();
    void saveFile();

private:
    std::string fileName_;
    std::map<std::string, std::vector<std::pair<int, int>>> playerResults_;

    void divideResultsIntoPlayers(const std::vector<std::string>& results);
    void splitString(const std::string& str, std::vector<std::string>& vec, char delimiter);
};
