#include <string>
#include <vector>

struct no_sum_num {
  std ::string s{"no possible way to solve task"};
};

std ::vector<int> find_nums(int k, std ::vector<int> sequence) {
  std ::vector<int> ans;
  unsigned long left_index{0};
  unsigned long right_index{sequence.size() - 1};
  while (left_index != right_index) {
    if ((sequence[left_index] + sequence[right_index]) == k) {
      ans.push_back(sequence[left_index]);
      ans.push_back(sequence[right_index]);
      return ans;
    } else if (sequence[left_index] + sequence[right_index] > k)
      --right_index;
    else
      ++left_index;
  }
  throw no_sum_num{};
}