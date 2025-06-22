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


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}