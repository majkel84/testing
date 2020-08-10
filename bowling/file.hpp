#pragma once

#include <string>

class File {
public:
    File(std::string fileName);
    void saveFile();
private:
    std::string fileName_;
};
