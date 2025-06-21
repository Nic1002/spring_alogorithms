#include <gtest/gtest.h>

#include <algorithm>
#include <stdexcept>
#include <vector>

#include "task_01.hpp"

TEST(FindTwoNumsTest, BasicMatch) {
  std::vector<int> arr = {1, 2, 3, 4, 6};
  auto result = find_two_nums(7, arr);  // 3 + 4
  std::sort(result.begin(), result.end());
  ASSERT_EQ(result, std::vector<int>({1, 6}));  // Stack []
}

TEST(FindTwoNumsTest, MultiplePairsPossible) {
  std::vector<int> arr = {1, 2, 3, 4, 4, 5};
  auto result = find_two_nums(8, arr);  // could be 3+5 or 4+4
  ASSERT_EQ(result[0] + result[1], 8);  // Stack []
}

TEST(FindTwoNumsTest, NoSolution) {
  std::vector<int> arr = {1, 2, 3};
  ASSERT_EQ(find_two_nums(10, arr), std::vector<int>{});  // Stack []
}

TEST(FindTwoNumsTest, NegativeNumbers) {
  std::vector<int> arr = {-5, -2, 0, 3, 7, 9};
  auto result = find_two_nums(4, arr);  // -5 + 9 = 4
  std::sort(result.begin(), result.end());
  ASSERT_EQ(result, std::vector<int>({-5, 9}));  // Stack []
}

TEST(FindTwoNumsTest, SameElementTwice) {
  std::vector<int> arr = {1, 2, 4, 4, 5, 6};
  auto result = find_two_nums(8, arr);  // 4 + 4
  std::sort(result.begin(), result.end());
  ASSERT_EQ(result, std::vector<int>({2, 6}));  // Stack []
}