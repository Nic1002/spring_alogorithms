#include <gtest/gtest.h>
#include <vector>
#include "solution.hpp"

using namespace std;

TEST(DailyTempTest, BasicTest) {
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
    EXPECT_EQ(DailyTemp(temps), expected);
}

TEST(DailyTempTest, NoWarming) {
    vector<int> temps = {80, 75, 70, 65, 60};
    vector<int> expected = {0, 0, 0, 0, 0};
    EXPECT_EQ(DailyTemp(temps), expected);
}

TEST(DailyTempTest, ImmediateWarming) {
    vector<int> temps = {50, 60, 70, 80, 90};
    vector<int> expected = {1, 1, 1, 1, 0};
    EXPECT_EQ(DailyTemp(temps), expected);
}

TEST(DailyTempTest, EmptyInput) {
    vector<int> temps = {};
    vector<int> expected = {};
    EXPECT_EQ(DailyTemp(temps), expected);
}

TEST(DailyTempTest, SingleDay) {
    vector<int> temps = {100};
    vector<int> expected = {0};
    EXPECT_EQ(DailyTemp(temps), expected);
}

TEST(DailyTempTest, MixedWarming) {
    vector<int> temps = {30, 40, 20, 25, 35, 10};
    vector<int> expected = {1, 0, 1, 1, 0, 0};
    EXPECT_EQ(DailyTemp(temps), expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}