#include <gtest/gtest.h>
#include "function.h"

TEST(NumbersTest, BasicTest) {
    std::vector<int> list = {1, 2, 3, 4, 5};
    auto result = Numbers(3, list);
    EXPECT_EQ(result.first, 2);
    EXPECT_EQ(result.second, 2);
}

TEST(NumbersTest, EmptyList) {
    std::vector<int> list;
    auto result = Numbers(5, list);
    EXPECT_EQ(result.first, 0);
    EXPECT_EQ(result.second, 0);
}

TEST(NumbersTest, AllEqual) {
    std::vector<int> list = {3, 3, 3, 3};
    auto result = Numbers(3, list);
    EXPECT_EQ(result.first, 0);
    EXPECT_EQ(result.second, 0);
}

TEST(NumbersTest, MixedNumbers) {
    std::vector<int> list = {-5, 0, 5, 10};
    auto result = Numbers(0, list);
    EXPECT_EQ(result.first, 1);
    EXPECT_EQ(result.second, 2);
}