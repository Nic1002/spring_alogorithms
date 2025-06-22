#include <gtest/gtest.h>
#include "weather.cpp"

TEST(DailyTemperaturesTest, BasicTest) {
    std::vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

TEST(DailyTemperaturesTest, SingleDay) {
    std::vector<int> input = {30};
    std::vector<int> expected = {0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

TEST(DailyTemperaturesTest, AllIncreasing) {
    std::vector<int> input = {10, 20, 30, 40};
    std::vector<int> expected = {1, 1, 1, 0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

TEST(DailyTemperaturesTest, AllDecreasing) {
    std::vector<int> input = {40, 30, 20, 10};
    std::vector<int> expected = {0, 0, 0, 0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

TEST(DailyTemperaturesTest, MixedTemperatures) {
    std::vector<int> input = {30, 40, 50, 60, 20, 25, 30, 15, 45};
    std::vector<int> expected = {1, 1, 1, 0, 1, 1, 2, 1, 0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

TEST(DailyTemperaturesTest, NoWarmDay) {
    std::vector<int> input = {50, 40, 30, 20};
    std::vector<int> expected = {0, 0, 0, 0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

TEST(DailyTemperaturesTest, ImmediateWarmDay) {
    std::vector<int> input = {10, 20, 10, 20};
    std::vector<int> expected = {1, 0, 1, 0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}