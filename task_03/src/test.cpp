#include <gtest/gtest.h>
#include "weather.h"

TEST(DailyTemperaturesTest, BasicTest) {
    std::vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
    EXPECT_EQ(DailyTemperatures(input), expected);
}

TEST(DailyTemperaturesTest, EmptyInput) {
    std::vector<int> input;
    std::vector<int> expected;
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