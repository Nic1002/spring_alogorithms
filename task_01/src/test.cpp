#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "two_numbers.h"

// Функция, которую мы тестируем
std::pair<int, int> find_sum(const std::vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;

  while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target) {
      return {left, right};
    } else if (sum < target) {
      left++;
    } else {
      right--;
    }
  }

  return {-1, -1};
}

// Тесты

// Тест 1: Обычный случай
TEST(FindTwoSumTest, BasicCase) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  std::pair<int, int> result = find_sum(nums, target);
  EXPECT_EQ(result.first, 0);
  EXPECT_EQ(result.second, 1);
}

// Тест 2: Нет подходящей пары
TEST(FindTwoSumTest, NoPairCase) {
  std::vector<int> nums = {1, 2, 3, 4};
  int target = 8;
  std::pair<int, int> result = find_sum(nums, target);
  EXPECT_EQ(result.first, -1);
  EXPECT_EQ(result.second, -1);
}

// Тест 3: Все числа одинаковые
TEST(FindTwoSumTest, AllElementsSame) {
  std::vector<int> nums = {5, 5, 5, 5};
  int target = 10;
  std::pair<int, int> result = find_sum(nums, target);
  EXPECT_EQ(result.first, 0);
  EXPECT_EQ(result.second, 1);
}

// Тест 4: Отрицательные числа
TEST(FindTwoSumTest, NegativeNumbers) {
  std::vector<int> nums = {-5, -3, 0, 1, 2};
  int target = -3;
  std::pair<int, int> result = find_sum(nums, target);
  EXPECT_EQ(result.first, 1);
  EXPECT_EQ(result.second, 2);
}

// Тест 5: Большой массив
TEST(FindTwoSumTest, LargeArray) {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int target = 17;
  std::pair<int, int> result = find_sum(nums, target);
  EXPECT_EQ(result.first, 7);
  EXPECT_EQ(result.second, 9);
}

// Тест 6: Массив из двух элементов
TEST(FindTwoSumTest, TwoElementsArray) {
  std::vector<int> nums = {1, 2};
  int target = 3;
  std::pair<int, int> result = find_sum(nums, target);
  EXPECT_EQ(result.first, 0);
  EXPECT_EQ(result.second, 1);
}

// Тест 7: Массив из одного элемента
TEST(FindTwoSumTest, SingleElementArray) {
  std::vector<int> nums = {1};
  int target = 1;
  std::pair<int, int> result = find_sum(nums, target);
  EXPECT_EQ(result.first, -1);
  EXPECT_EQ(result.second, -1);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}