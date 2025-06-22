#include <gtest/gtest.h>
#include <vector>
#include <random>
#include <algorithm>
#include "solution.hpp"

template <typename T>
void TestSorting(T* arr, int size) {
    QuickSort(arr, 0, size - 1);
    for (int i = 1; i < size; ++i) {
        ASSERT_LE(arr[i - 1], arr[i]);
    }
}

TEST(QuickSortTest, EmptyArray) {
    int arr[] = {};
    ASSERT_NO_THROW(QuickSort(arr, 0, -1));
}

TEST(QuickSortTest, SingleElement) {
    int arr[] = {42};
    TestSorting(arr, 1);
}

TEST(QuickSortTest, SortedArray) {
    int arr[] = {1, 2, 3, 4, 5};
    TestSorting(arr, 5);
}

TEST(QuickSortTest, ReverseSortedArray) {
    int arr[] = {5, 4, 3, 2, 1};
    TestSorting(arr, 5);
}

TEST(QuickSortTest, RandomArray) {
    std::vector<int> arr(100);
    std::iota(arr.begin(), arr.end(), 0);
    std::shuffle(arr.begin(), arr.end(), std::mt19937{std::random_device{}()});
    TestSorting(arr.data(), arr.size());
}

TEST(QuickSortTest, DuplicateElements) {
    int arr[] = {2, 2, 1, 1, 3, 3};
    TestSorting(arr, 6);
}

TEST(QuickSortTest, FloatArray) {
    float arr[] = {1.5f, 0.5f, 2.5f, 1.1f, 3.3f};
    TestSorting(arr, 5);
}

TEST(QuickSortTest, LargeRandomArray) {
    std::vector<int> arr(10000);
    std::iota(arr.begin(), arr.end(), 0);
    std::shuffle(arr.begin(), arr.end(), std::mt19937{std::random_device{}()});
    TestSorting(arr.data(), arr.size());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}