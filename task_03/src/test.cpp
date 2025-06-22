#include <gtest/gtest.h>
#include "weather.cpp"

TEST(DailyTemperaturesTest, BasicCase) {
    std::vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

TEST(DailyTemperaturesTest, SingleDay) {
    std::vector<int> input = {30};
    std::vector<int> expected = {0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

TEST(DailyTemperaturesTest, NoWarmDays) {
    std::vector<int> input = {50, 40, 30, 20};
    std::vector<int> expected = {0, 0, 0, 0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

TEST(DailyTemperaturesTest, ImmediateWarmDay) {
    std::vector<int> input = {10, 20};
    std::vector<int> expected = {1, 0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

TEST(DailyTemperaturesTest, MixedTemperatures) {
    std::vector<int> input = {30, 50, 40, 60};
    std::vector<int> expected = {1, 2, 1, 0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

TEST(DailyTemperaturesTest, AllIncreasing) {
    std::vector<int> input = {10, 20, 30, 40};
    std::vector<int> expected = {1, 1, 1, 0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}