#include "merge_sort.hpp"

int _max(int a, int b) { return a >= b ? a : b; }
int _min(int a, int b) { return a <= b ? a : b; }

std::vector<int> _slice(const std::vector<int>& vector, const size_t from,
                        const size_t to) {
  if (from < to)
    return std::vector<int>{vector.begin() + from, vector.begin() + to};
  else
    return std::vector<int>{};
}

std::vector<int> _merge(std::vector<int>& left, std::vector<int>& right) {
  std::vector<int> nw;
  size_t i_l = 0;
  size_t i_r = 0;
  size_t size_l = left.size();
  size_t size_r = right.size();
  while (i_l < size_l && i_r < size_r) {
    if (left[i_l] < right[i_r]) {
      nw.push_back(left[i_l]);
      ++i_l;
    } else {
      nw.push_back(right[i_r]);
      ++i_r;
    }
  }
  if (i_l >= size_l) {
    for (size_t i = i_r; i < size_r; ++i) nw.push_back(right[i]);
    return nw;
  }
  if (i_r >= size_r) {
    for (size_t i = i_l; i < size_l; ++i) nw.push_back(left[i]);
    return nw;
  }
  return nw;
}
void merge_sort(std::vector<int>& vec) {
  int n = vec.size();
  if (n <= 1) return;
  std::vector<int> left = _slice(vec, 0, n / 2);
  std::vector<int> right = _slice(vec, n / 2, n);

  merge_sort(left);
  merge_sort(right);

  vec = _merge(left, right);
}