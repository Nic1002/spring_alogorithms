#include <gtest/gtest.h>
#include "fish.h"

TEST(FishShoppingTest, BasicTest) {
    std::vector<int> prices = {5, 3, 4};
    int K = 3;
    EXPECT_EQ(SolveFishShopping(prices, K), 11);
}

TEST(FishShoppingTest, IncreasingPrices) {
    std::vector<int> prices = {1, 2, 3};
    int K = 3;
    EXPECT_EQ(SolveFishShopping(prices, K), 3);
}

TEST(FishShoppingTest, DecreasingPrices) {
    std::vector<int> prices = {5, 4, 3};
    int K = 3;
    EXPECT_EQ(SolveFishShopping(prices, K), 12);
}

TEST(FishShoppingTest, MixedPrices) {
    std::vector<int> prices = {3, 1, 2};
    int K = 3;
    EXPECT_EQ(SolveFishShopping(prices, K), 5);
}

TEST(FishShoppingTest, SingleDay) {
    std::vector<int> prices = {10};
    int K = 1;
    EXPECT_EQ(SolveFishShopping(prices, K), 10);
}

TEST(FishShoppingTest, EmptyPrices) {
    std::vector<int> prices;
    int K = 3;
    EXPECT_EQ(SolveFishShopping(prices, K), 0);
}