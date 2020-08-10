#include <gtest/gtest.h>

#include <string>

#include "file.hpp"

struct TestFile : public ::testing::Test {
    File file = File("file.txt");
};

TEST_F(TestFile, checkSaveGameNoThrow) {
   ASSERT_NO_THROW(file.saveFile());
}
