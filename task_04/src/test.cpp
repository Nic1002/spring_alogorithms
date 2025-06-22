#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include "solution.hpp"
using namespace std;

TEST(BFishTest, SingleDay) {
    vector<int> prices = {5};
    auto result = BFish(prices, 1);
    vector<pair<int, int>> expected = {{0, 0}};
    ASSERT_EQ(result, expected);
}

TEST(BFishTest, KGreaterThanN) {
    vector<int> prices = {5, 3, 4};
    auto result = BFish(prices, 5);
    vector<pair<int, int>> expected = {{1, 2}};
    ASSERT_EQ(result, expected);
}

TEST(BFishTest, EmptyInput) {
    vector<int> prices;
    auto result = BFish(prices, 3);
    ASSERT_TRUE(result.empty());
}