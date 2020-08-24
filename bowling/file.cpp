#include "file.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

File::File(std::string fileName) : fileName_(fileName) {}

std::vector<std::pair<int, int>> File::getScores() const {
    return score_;
}

std::string File::getResults() const {
    return results_;
}

void File::splitString(const std::string& str, std::vector<std::string>& vec) {
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        vec.push_back(token);
    }
}

void File::translateResultsToScoreVector(std::string results) {
    std::vector<std::string> results_divided;
    std::vector<int> temp{};

    this->splitString(results, results_divided);

    for (auto elem : results_divided) {
        if (elem.empty()) {
            continue;
        } else if (elem == "X") {
            this->score_.push_back(std::make_pair(10, 0));
        } else if (elem == "XX") {
            this->score_.push_back(std::make_pair(10, 0));
            this->score_.push_back(std::make_pair(10, 0));
        } else if (elem == "--") {
            this->score_.push_back(std::make_pair(0, 0));
        } else {
            for (int i = 0; i < 2; i++) {
                if (elem[i] == '-') {
                    temp.push_back(0);
                } else if (std::isdigit(elem[i])) {
                    temp.push_back((int)elem[i] - 48);
                } else if (elem[i] == '/') {
                    temp.push_back(10 - temp[0]);
                } else {
                    temp.push_back(0);
                }
            }
            this->score_.push_back(std::make_pair(temp[0], temp[1]));
            temp.clear();
        }
    }
}

void File::readFile() {
    std::string line;
    std::ifstream lane(this->fileName_);
    if (lane.is_open()) {
        while (getline(lane, line)) {
            this->results_ = line;
        }
        lane.close();
    } else {
        std::cerr << "Could not open file ...";
    }
}

void File::saveFile() {
    namespace fs = std::filesystem;
    fs::path path = fs::current_path();
    fs::create_directories(path.parent_path());
    std::ofstream ofs(path);
    if (!ofs) {
        std::cerr << "Could not open " << fileName_ << " for writing!\n";
    } else {
        ofs << "score";
        ofs.close();
    }
}
