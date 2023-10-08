#include "LongArithmetic.hpp"
#include <gtest/gtest.h>

class LongNumberTests : public ::testing::Test {
protected:
    int h;
};

TEST_F(LongNumberTests, firstone) {
    ASSERT_EQ(111, 111);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}