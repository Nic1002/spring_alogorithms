#include "two_numbers.hpp"

#include <utility>

std::pair<int, int> FindSum::findTwoSum(const std::vector<int>& nums,
                                        int target) {
  int left = 0;
  int right = nums.size() - 1;

  while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target) {
      return {nums[left], nums[right]};
    } else if (sum < target) {
      left++;
    } else {
      right--;
    }
  }

  return {-1, -1};  // Если пара не найдена
}
