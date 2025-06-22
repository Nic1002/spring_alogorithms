#include <gtest/gtest.h>
#include "solution.hpp"

TEST(TableSortTest, BasicTest) {
    vector<vector<int>> table = {
        {1, 2, 3},
        {2, 1, 4},
        {3, 2, 1}
    };
    int n = 3, m = 3;
    
    auto segment_start = ComputeSegmentStart(table, n, m);
    auto row_max_good = ComputeRowMaxGood(segment_start, n, m);
    
    EXPECT_TRUE(CanSort(row_max_good, 0, 0));
    EXPECT_TRUE(CanSort(row_max_good, 0, 1));
    EXPECT_FALSE(CanSort(row_max_good, 0, 2));
    EXPECT_TRUE(CanSort(row_max_good, 1, 2));
}

TEST(TableSortTest, SingleColumnSorted) {
    vector<vector<int>> table = {
        {1},
        {2},
        {3}
    };
    int n = 3, m = 1;
    
    auto segment_start = ComputeSegmentStart(table, n, m);
    auto row_max_good = ComputeRowMaxGood(segment_start, n, m);
    
    EXPECT_TRUE(CanSort(row_max_good, 0, 2));
    EXPECT_TRUE(CanSort(row_max_good, 1, 2));
}

TEST(TableSortTest, SingleColumnUnsorted) {
    vector<vector<int>> table = {
        {3},
        {2},
        {1}
    };
    int n = 3, m = 1;
    
    auto segment_start = ComputeSegmentStart(table, n, m);
    auto row_max_good = ComputeRowMaxGood(segment_start, n, m);
    
    EXPECT_FALSE(CanSort(row_max_good, 0, 2));
    EXPECT_FALSE(CanSort(row_max_good, 1, 2));
    EXPECT_TRUE(CanSort(row_max_good, 2, 2));
}

TEST(TableSortTest, MultipleColumnsMixed) {
    vector<vector<int>> table = {
        {1, 5, 2},
        {2, 4, 2},
        {3, 3, 3},
        {4, 2, 4},
        {5, 1, 5}
    };
    int n = 5, m = 3;
    
    auto segment_start = ComputeSegmentStart(table, n, m);
    auto row_max_good = ComputeRowMaxGood(segment_start, n, m);
    
    EXPECT_TRUE(CanSort(row_max_good, 0, 4));
    EXPECT_TRUE(CanSort(row_max_good, 0, 2));
    EXPECT_FALSE(CanSort(row_max_good, 1, 4));
    EXPECT_TRUE(CanSort(row_max_good, 2, 4));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}