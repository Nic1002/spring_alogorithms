#include "quick_sort.hpp"

void QuickSort(std::vector<int>& vec, int first, int last) {
  if (last - first <= 0) return;
  int index_big = last + 1;
  for (size_t i = first + 1; i <= last; ++i) {
    if (vec[i] > vec[first]) {
      if (index_big != last + 1) continue;
      index_big = i;
    } else {
      if (index_big == last + 1)
        continue;
      else {
        int tmp = vec[index_big];
        vec[index_big] = vec[i];
        vec[i] = tmp;
        index_big++;
      }
    }
  }
  int tmp = vec[index_big - 1];
  vec[index_big - 1] = vec[first];
  vec[first] = tmp;
  QuickSort(vec, first, index_big - 2);
  QuickSort(vec, index_big, last);
}