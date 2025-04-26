#include "q_sort.hpp"

#include <algorithm>
#include <cstdlib>

int Partition(std::vector<int> &arr, int low, int high) {
  int pivot_index = low + rand() % (high - low + 1);
  int pivot = arr[pivot_index];

  std::swap(arr[pivot_index], arr[high]);

  int i = low;  // Указатель на место для следующего меньшего элемента

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      std::swap(arr[i], arr[j]);
      i++;
    }
  }
  // Возвращаем опорный элемент на правильную позицию
  std::swap(arr[i], arr[high]);
  return i;
}

void QSort(std::vector<int> &arr, int low, int high) {
  if (low < high) {
    // pi - индекс разделения, arr[pi] теперь на правильном месте
    int pi = Partition(arr, low, high);

    QSort(arr, low, pi - 1);
    QSort(arr, pi + 1, high);
  }
}

void QSortNew(std::vector<int> &arr) { QSort(arr, 0, arr.size() - 1); }
