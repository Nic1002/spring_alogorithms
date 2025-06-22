#include <gtest/gtest.h>
#include "solution.hpp"

TEST(OrderStatTest, SingleElement) {
    vector<int> arr = {42};
    EXPECT_EQ(FindOrderStat(arr, 0), 42);
}

TEST(OrderStatTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    EXPECT_EQ(FindOrderStat(arr, 2), 3);
}

TEST(OrderStatTest, ReverseSorted) {
    vector<int> arr = {5, 4, 3, 2, 1};
    EXPECT_EQ(FindOrderStat(arr, 2), 3);
}

TEST(OrderStatTest, InvalidK) {
    vector<int> arr = {1, 2, 3};
    
    EXPECT_THROW(FindOrderStat(arr, -1), out_of_range);
    EXPECT_THROW(FindOrderStat(arr, 3), out_of_range);
    EXPECT_THROW(FindOrderStat(vector<int>(), 0), out_of_range);
}

TEST(OrderStatTest, Duplicates) {
    vector<int> arr = {2, 2, 2, 2, 2};
    for (int k = 0; k < 5; ++k) {
        EXPECT_EQ(FindOrderStat(arr, k), 2);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}