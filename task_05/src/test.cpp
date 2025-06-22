#include <gtest/gtest.h>
#include "merge_sort.h"
#include <algorithm>
#include <cstdlib>

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

TEST(MergeSortTest, AlreadySorted) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> sorted = arr;
    MergeSort(arr);
    EXPECT_EQ(arr, sorted);
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
    std::vector<int> arr = {2, 1, 2, 1, 3, 2};
    std::vector<int> expected = {1, 1, 2, 2, 2, 3};
    MergeSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, NegativeNumbers) {
    std::vector<int> arr = {0, -3, 5, -2, 1};
    std::vector<int> expected = {-3, -2, 0, 1, 5};
    MergeSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, LargeInput) {
    const int N = 1000;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 1000;
    }
    
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    
    MergeSort(arr);
    EXPECT_EQ(arr, expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}