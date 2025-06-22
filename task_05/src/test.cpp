#include "heap.hpp"
#include <gtest/gtest.h>
#include <algorithm>

TEST(HeapSortTest, SortsIntegersCorrectly) {
    std::vector<int> input = {5, 2, 9, 1, 5, 6};
    std::vector<int> expected = {1, 2, 5, 5, 6, 9};
    std::vector<int> result = Heap_sort(input);
    
    EXPECT_EQ(result, expected);
    EXPECT_TRUE(std::is_sorted(result.begin(), result.end()));
}

TEST(HeapSortTest, HandlesEmptyVector) {
    std::vector<double> input = {};
    std::vector<double> result = Heap_sort(input);
    
    EXPECT_TRUE(result.empty());
}