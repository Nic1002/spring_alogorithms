#include <gtest/gtest.h>
#include "statistic.cpp"

TEST(QuickSelectTest, BasicFunctionality) {
    std::vector<int> arr = {3, 1, 4, 2, 5};
    EXPECT_EQ(KthOrderStatistic(arr, 0), 1);
    EXPECT_EQ(KthOrderStatistic(arr, 1), 2);
    EXPECT_EQ(KthOrderStatistic(arr, 2), 3);
    EXPECT_EQ(KthOrderStatistic(arr, 3), 4);
    EXPECT_EQ(KthOrderStatistic(arr, 4), 5);
}

TEST(QuickSelectTest, Duplicates) {
    std::vector<int> arr = {2, 1, 1, 3, 2};
    EXPECT_EQ(KthOrderStatistic(arr, 0), 1);
    EXPECT_EQ(KthOrderStatistic(arr, 1), 1);
    EXPECT_EQ(KthOrderStatistic(arr, 2), 2);
    EXPECT_EQ(KthOrderStatistic(arr, 3), 2);
    EXPECT_EQ(KthOrderStatistic(arr, 4), 3);
}

TEST(QuickSelectTest, ReverseSorted) {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(KthOrderStatistic(arr, i), i + 1);
    }
}

TEST(QuickSelectTest, EdgeCases) {
    std::vector<int> single = {42};
    EXPECT_EQ(KthOrderStatistic(single, 0), 42);
    
    std::vector<int> empty;
    EXPECT_THROW(KthOrderStatistic(empty, 0), std::invalid_argument);
    
    std::vector<int> two = {2, 1};
    EXPECT_EQ(KthOrderStatistic(two, 0), 1);
    EXPECT_EQ(KthOrderStatistic(two, 1), 2);
}

TEST(QuickSelectTest, NegativeNumbers) {
    std::vector<int> arr = {0, -5, 3, -2, 7};
    EXPECT_EQ(KthOrderStatistic(arr, 0), -5);
    EXPECT_EQ(KthOrderStatistic(arr, 1), -2);
    EXPECT_EQ(KthOrderStatistic(arr, 2), 0);
    EXPECT_EQ(KthOrderStatistic(arr, 3), 3);
    EXPECT_EQ(KthOrderStatistic(arr, 4), 7);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}