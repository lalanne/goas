
#include "MemoryMap.hpp"
#include "NotFileFoundException.hpp"

#include <gtest/gtest.h>

TEST(MemoryMapTests, trying_to_open_file_does_NOT_exist){
    MemoryMap mmap("no_file.dat");
    EXPECT_THROW(mmap.open_file(),NotFileFoundException);
}

