#include <gtest/gtest.h>
#include "tables.cpp"

TEST(TableSorterTest, SingleRow) {
    vector<vector<int>> a = {{5}};
    TableSorter ts(a);
    EXPECT_TRUE(ts.query(1, 1));
}

TEST(TableSorterTest, TwoRowsOneColumn_Sorted) {
    vector<vector<int>> a = {{1}, {2}};
    TableSorter ts(a);
    EXPECT_TRUE(ts.query(1, 2));
}

TEST(TableSorterTest, TwoRowsOneColumn_NotSorted) {
    vector<vector<int>> a = {{2}, {1}};
    TableSorter ts(a);
    EXPECT_FALSE(ts.query(1, 2));
}

TEST(TableSorterTest, TwoRowsTwoColumns_OneSorted) {
    vector<vector<int>> a = {{2, 1}, {1, 2}};
    TableSorter ts(a);
    EXPECT_TRUE(ts.query(1, 2));
}

TEST(TableSorterTest, TwoRowsTwoColumns_BothNotSorted) {
    vector<vector<int>> a = {{3, 2}, {1, 0}};
    TableSorter ts(a);
    EXPECT_FALSE(ts.query(1, 2));
}

TEST(TableSorterTest, ThreeRowsOneSortedColumn) {
    vector<vector<int>> a = {
        {1, 5},
        {2, 3},
        {3, 1}
    };
    TableSorter ts(a);
    EXPECT_TRUE(ts.query(1, 3));
    EXPECT_TRUE(ts.query(1, 2));
    EXPECT_TRUE(ts.query(2, 3));
}

TEST(TableSorterTest, ThreeRowsNoSortedColumn) {
    vector<vector<int>> a = {
        {5, 4},
        {3, 2},
        {1, 0}
    };
    TableSorter ts(a);
    EXPECT_FALSE(ts.query(1, 3));
    EXPECT_FALSE(ts.query(1, 2));
    EXPECT_FALSE(ts.query(2, 3));
    EXPECT_TRUE(ts.query(1, 1));
    EXPECT_TRUE(ts.query(2, 2));
    EXPECT_TRUE(ts.query(3, 3));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}