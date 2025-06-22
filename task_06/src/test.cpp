#include <gtest/gtest.h>
#include "statistic.cpp"

TEST(OrderStatisticTest, BasicTest) {
    std::vector<int> arr = {3, 1, 4, 2, 5};
    EXPECT_EQ(KthOrderStatistic(arr, 0), 1);
    EXPECT_EQ(KthOrderStatistic(arr, 1), 2);
    EXPECT_EQ(KthOrderStatistic(arr, 2), 3);
    EXPECT_EQ(KthOrderStatistic(arr, 3), 4);
    EXPECT_EQ(KthOrderStatistic(arr, 4), 5);
}

TEST(OrderStatisticTest, SingleElement) {
    std::vector<int> arr = {42};
    EXPECT_EQ(KthOrderStatistic(arr, 0), 42);
}

TEST(OrderStatisticTest, Duplicates) {
    std::vector<int> arr = {2, 2, 1, 1, 3, 3};
    EXPECT_EQ(KthOrderStatistic(arr, 0), 1);
    EXPECT_EQ(KthOrderStatistic(arr, 1), 1);
    EXPECT_EQ(KthOrderStatistic(arr, 2), 2);
    EXPECT_EQ(KthOrderStatistic(arr, 3), 2);
    EXPECT_EQ(KthOrderStatistic(arr, 4), 3);
    EXPECT_EQ(KthOrderStatistic(arr, 5), 3);
}

TEST(OrderStatisticTest, SortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(KthOrderStatistic(arr, i), i + 1);
    }
}

TEST(OrderStatisticTest, ReverseSorted) {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(KthOrderStatistic(arr, i), i + 1);
    }
}

TEST(OrderStatisticTest, LargeArray) {
    std::vector<int> arr(1000);
    for (int i = 0; i < 1000; i++) {
        arr[i] = 1000 - i;
    }
    
    for (int k = 0; k < 1000; k++) {
        EXPECT_EQ(KthOrderStatistic(arr, k), k + 1);
    }
}

TEST(OrderStatisticTest, EdgeValues) {
    std::vector<int> arr = {2147483647, -2147483648, 0};
    EXPECT_EQ(KthOrderStatistic(arr, 0), -2147483648);
    EXPECT_EQ(KthOrderStatistic(arr, 1), 0);
    EXPECT_EQ(KthOrderStatistic(arr, 2), 2147483647);
}

TEST(OrderStatisticTest, InvalidInput) {
    std::vector<int> empty;
    EXPECT_THROW(KthOrderStatistic(empty, 0), std::invalid_argument);
    
    std::vector<int> arr = {1, 2, 3};
    EXPECT_THROW(KthOrderStatistic(arr, -1), std::out_of_range);
    EXPECT_THROW(KthOrderStatistic(arr, 3), std::out_of_range);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}