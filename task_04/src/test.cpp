#include "fish.cpp"
#include <gtest/gtest.h>

TEST(FishShoppingTest, BasicTest) {
    vector<int> prices = {5, 3, 4};
    int K = 3;
    EXPECT_EQ(solveFishShopping(prices, K), 11);
}

TEST(FishShoppingTest, IncreasingPrices) {
    vector<int> prices = {1, 2, 3};
    int K = 3;
    EXPECT_EQ(solveFishShopping(prices, K), 3);
}

TEST(FishShoppingTest, DecreasingPrices) {
    vector<int> prices = {5, 4, 3};
    int K = 3;
    EXPECT_EQ(solveFishShopping(prices, K), 12);
}

TEST(FishShoppingTest, MixedPrices) {
    vector<int> prices = {3, 1, 2};
    int K = 3;
    EXPECT_EQ(solveFishShopping(prices, K), 5);
}

TEST(FishShoppingTest, SingleDay) {
    vector<int> prices = {10};
    int K = 1;
    EXPECT_EQ(solveFishShopping(prices, K), 10);
}

TEST(FishShoppingTest, TwoDaysDecreasing) {
    vector<int> prices = {10, 5};
    int K = 2;
    EXPECT_EQ(solveFishShopping(prices, K), 15);
}

TEST(FishShoppingTest, TwoDaysIncreasing) {
    vector<int> prices = {5, 10};
    int K = 2;
    EXPECT_EQ(solveFishShopping(prices, K), 10);
}

TEST(FishShoppingTest, LargeK) {
    vector<int> prices = {5, 10, 15};
    int K = 100;
    EXPECT_EQ(solveFishShopping(prices, K), 15);
}

TEST(FishShoppingTest, K1) {
    vector<int> prices = {3, 2, 1};
    int K = 1;
    EXPECT_EQ(solveFishShopping(prices, K), 6);
}

TEST(FishShoppingTest, EmptyPrices) {
    vector<int> prices;
    int K = 3;
    EXPECT_EQ(solveFishShopping(prices, K), 0);
}

TEST(FishShoppingTest, LargeN) {
    vector<int> prices(1000, 10);
    int K = 10;
    long long expected = static_cast<long long>(10) * 1000;
    EXPECT_EQ(solveFishShopping(prices, K), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}