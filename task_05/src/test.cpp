#include <gtest/gtest.h>
#include "merge_sort.cpp"
#include <algorithm>

TEST(MergeSortTest, EmptyArray) {
    std::vector<int> arr;
    MergeSort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(MergeSortTest, SingleElement) {
    std::vector<int> arr = {5};
    MergeSort(arr);
    EXPECT_EQ(arr, std::vector<int>({5}));
}

TEST(MergeSortTest, SortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = arr;
    MergeSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, ReverseSorted) {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    MergeSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, RandomOrder) {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    std::vector<int> expected = {1, 1, 2, 3, 4, 5, 6, 9};
    MergeSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, Duplicates) {
    std::vector<int> arr = {2, 2, 2, 1, 1, 3, 3};
    std::vector<int> expected = {1, 1, 2, 2, 2, 3, 3};
    MergeSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, LargeArray) {
    std::vector<int> arr(1000);
    for (int i = 0; i < 1000; i++) {
        arr[i] = 1000 - i;
    }
    
    std::vector<int> expected(1000);
    for (int i = 0; i < 1000; i++) {
        expected[i] = i + 1;
    }
    
    MergeSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, AllEqual) {
    std::vector<int> arr(100, 5);
    std::vector<int> expected = arr;
    MergeSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, NegativeNumbers) {
    std::vector<int> arr = {-5, 3, -2, 0, 7, -1};
    std::vector<int> expected = {-5, -2, -1, 0, 3, 7};
    MergeSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, MixedNumbers) {
    std::vector<int> arr = {5, -3, 0, 12, -8, 7};
    std::vector<int> expected = {-8, -3, 0, 5, 7, 12};
    MergeSort(arr);
    EXPECT_EQ(arr, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}