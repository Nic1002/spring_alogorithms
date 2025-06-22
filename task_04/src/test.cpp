#include <gtest/gtest.h>
#include <vector>
#include <utility> 
#include "fish.hpp"

TEST(TopologySort, Simple) {
    ASSERT_EQ(1, 1);
}

TEST(BuyFishTest, BasicCase) {
    std::vector<int> prices = {3, 2, 5, 4, 1, 6};
    int K = 3;
    std::vector<std::pair<int, int>> expected = {
        {1, 3}, // Покупаем на 2-й день (цена 2) на 3 дня
        {4, 2}   // Покупаем на 5-й день (цена 1) на оставшиеся 2 дня
    };
    auto result = buyFishSimplified(prices, K);
    ASSERT_EQ(result, expected);
}

TEST(BuyFishTest, SingleDay) {
    std::vector<int> prices = {5};
    int K = 1;
    std::vector<std::pair<int, int>> expected = {
        {0, 1} // Покупаем в единственный день
    };
    auto result = buyFishSimplified(prices, K);
    ASSERT_EQ(result, expected);
}

TEST(BuyFishTest, SmallShelfLife) {
    std::vector<int> prices = {4, 3, 2, 1, 5, 6};
    int K = 1; // Рыба портится сразу
    std::vector<std::pair<int, int>> expected = {
        {0, 1}, // Покупаем каждый день отдельно
        {1, 1},
        {2, 1},
        {3, 1},
        {4, 1},
        {5, 1}
    };
    auto result = buyFishSimplified(prices, K);
    ASSERT_EQ(result, expected);
}

TEST(BuyFishTest, ConstantPrices) {
    std::vector<int> prices = {2, 2, 2, 2, 2};
    int K = 5; // Большой срок хранения
    std::vector<std::pair<int, int>> expected = {
        {0, 5} // Покупаем в первый день на все 5 дней
    };
    auto result = buyFishSimplified(prices, K);
    ASSERT_EQ(result, expected);
}