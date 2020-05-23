#include "gtest/gtest.h"


//source: http://www.yolinux.com/TUTORIALS/Cpp-GoogleTest.html

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}