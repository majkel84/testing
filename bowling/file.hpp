#pragma once

#include <string>

class File {
    File(std::string fileName);
    void saveFile();
private:
    std::string fileName_;
};
