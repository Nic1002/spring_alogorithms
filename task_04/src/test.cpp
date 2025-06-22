#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include "solution.hpp" 

TEST(BFishTest, BasicCase) {
    vector<int> prices = {3, 2, 1, 5, 4};
    int k = 2;
    vector<pair<int, int>> expected = {{1, 2}, {4, 1}};
    auto result = BFish(prices, k);
    ASSERT_EQ(result, expected);
}

TEST(BFishTest, AllDaysSamePrice) {
    vector<int> prices = {5, 5, 5, 5, 5};
    int k = 3;
    vector<pair<int, int>> expected = {{0, 5}};
    auto result = BFish(prices, k);
    ASSERT_EQ(result, expected);
}

TEST(BFishTest, KEqualsOne) {
    vector<int> prices = {4, 3, 2, 5, 1};
    int k = 1;
    vector<pair<int, int>> expected = {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}};
    auto result = BFish(prices, k);
    ASSERT_EQ(result, expected);
}

TEST(BFishTest, KGreaterThanN) {
    vector<int> prices = {5, 3, 4, 2, 6};
    int k = 10;
    vector<pair<int, int>> expected = {{3, 5}};
    auto result = BFish(prices, k);
    ASSERT_EQ(result, expected);
}

TEST(BFishTest, DecreasingPrices) {
    vector<int> prices = {5, 4, 3, 2, 1};
    int k = 2;
    vector<pair<int, int>> expected = {{1, 2}, {3, 2}};
    auto result = BFish(prices, k);
    ASSERT_EQ(result, expected);
}

TEST(BFishTest, SingleDay) {
    vector<int> prices = {10};
    int k = 5;
    vector<pair<int, int>> expected = {{0, 1}};
    auto result = BFish(prices, k);
    ASSERT_EQ(result, expected);
}

TEST(BFishTest, EmptyInput) {
    vector<int> prices = {};
    int k = 3;
    vector<pair<int, int>> expected = {};
    auto result = BFish(prices, k);
    ASSERT_EQ(result, expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}