#include <gtest/gtest.h>
#include "tables.cpp"

TEST(TableSorterTest, SingleRowAlwaysSorted) {
    vector<vector<int>> table = {{5}};
    TableSorter ts(table);
    EXPECT_TRUE(ts.query(1, 1));
}

TEST(TableSorterTest, TwoRowsSortedColumn) {
    vector<vector<int>> table = {{1}, {2}};
    TableSorter ts(table);
    EXPECT_TRUE(ts.query(1, 2));
}

TEST(TableSorterTest, TwoRowsUnsortedColumn) {
    vector<vector<int>> table = {{2}, {1}};
    TableSorter ts(table);
    EXPECT_FALSE(ts.query(1, 2));
}

TEST(TableSorterTest, MultipleColumnsWithOneSorted) {
    vector<vector<int>> table = {
        {3, 1, 4},
        {2, 2, 5},
        {1, 3, 6}
    };
    TableSorter ts(table);
    EXPECT_TRUE(ts.query(1, 3));
}

TEST(TableSorterTest, MultipleColumnsAllUnsorted) {
    vector<vector<int>> table = {
        {5, 4, 3},
        {4, 3, 2},
        {3, 2, 1}
    };
    TableSorter ts(table);
    EXPECT_FALSE(ts.query(1, 3));
}

TEST(TableSorterTest, SubrangeSorted) {
    vector<vector<int>> table = {
        {5, 1},
        {4, 2},
        {3, 3},
        {2, 4}
    };
    TableSorter ts(table);
    EXPECT_TRUE(ts.query(2, 4));
}

TEST(TableSorterTest, SubrangeUnsorted) {
    vector<vector<int>> table = {
        {1, 10},
        {3, 9},
        {2, 8},
        {4, 7}
    };
    TableSorter ts(table);
    EXPECT_FALSE(ts.query(1, 3));
}

TEST(TableSorterTest, SingleColumnMultipleQueries) {
    vector<vector<int>> table = {{1}, {3}, {2}, {4}};
    TableSorter ts(table);
    EXPECT_TRUE(ts.query(1, 1));
    EXPECT_TRUE(ts.query(1, 2));
    EXPECT_FALSE(ts.query(2, 3));
    EXPECT_TRUE(ts.query(3, 4));
    EXPECT_FALSE(ts.query(1, 4));
}

TEST(TableSorterTest, LargeGapInSortedColumn) {
    vector<vector<int>> table = {
        {10, 1},
        {20, 5},
        {15, 10},
        {25, 15},
        {30, 20}
    };
    TableSorter ts(table);
    EXPECT_TRUE(ts.query(1, 5));
    EXPECT_FALSE(ts.query(1, 3));
}

TEST(TableSorterTest, TwoRowsTwoColumnsOneSorted) {
    vector<vector<int>> table = {{2, 1}, {1, 2}};
    TableSorter ts(table);
    EXPECT_TRUE(ts.query(1, 2));
}

TEST(TableSorterTest, TwoRowsTwoColumnsBothUnsorted) {
    vector<vector<int>> table = {{3, 2}, {1, 0}};
    TableSorter ts(table);
    EXPECT_FALSE(ts.query(1, 2));
}

TEST(TableSorterTest, EdgeCaseSingleRowMultiColumn) {
    vector<vector<int>> table = {{1, 2, 3}};
    TableSorter ts(table);
    EXPECT_TRUE(ts.query(1, 1));
}

TEST(TableSorterTest, LastColumnSorted) {
    vector<vector<int>> table = {
        {5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5}
    };
    TableSorter ts(table);
    EXPECT_TRUE(ts.query(1, 2));
}

TEST(TableSorterTest, MiddleColumnSorted) {
    vector<vector<int>> table = {
        {5, 1, 4},
        {3, 2, 5},
        {1, 3, 6}
    };
    TableSorter ts(table);
    EXPECT_TRUE(ts.query(1, 3));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}