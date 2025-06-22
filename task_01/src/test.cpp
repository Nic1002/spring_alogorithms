#include <gtest/gtest.h>

#include "two_numbers.hpp"

TEST(TwoSumTest, BasicTest) {
  std::vector<int> nums = {2, 7, 11, 15};
  auto result = FindSum::findTwoSum(nums, 9);
  EXPECT_EQ(result.first, 2);
  EXPECT_EQ(result.second, 7);
}

TEST(TwoSumTest, NoSolution) {
  std::vector<int> nums = {1, 2, 3, 4};
  auto result = FindSum::findTwoSum(nums, 10);
  EXPECT_EQ(result.first, -1);
  EXPECT_EQ(result.second, -1);
}

TEST(TwoSumTest, DuplicateNumbers) {
  std::vector<int> nums = {3, 3, 4, 4};
  auto result = FindSum::findTwoSum(nums, 7);
  EXPECT_TRUE((result == std::pair<int, int>{3, 4}));
}

TEST(TwoSumTest, EmptyArray) {
  std::vector<int> nums;
  auto result = FindSum::findTwoSum(nums, 5);
  EXPECT_EQ(result.first, -1);
  EXPECT_EQ(result.second, -1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}