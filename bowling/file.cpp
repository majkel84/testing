#include "file.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

File::File(std::string fileName)
    : fileName_(fileName) {}

void File::saveFile() {
    namespace fs = std::filesystem;
    fs::path path = fs::current_path();
    fs::create_directories(path.parent_path());
    std::ofstream ofs(path);
    if(!ofs)
    {
        std::cerr << "Could not open " << fileName_ << " for writing!\n";
    } else {
        ofs << "score";
        ofs.close();
    }

}
