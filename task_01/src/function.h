#pragma once
#include <iostream>
#include <utility>
#include <vector>

inline std::pair<int, int> Numbers(int n, const std::vector<int>& list) {
  int less = 0;
  int greater = 0;

  for (int num : list) {
    if (num < n) {
      less++;
    } else if (num > n) {
      greater++;
    }
  }

  return {less, greater};
}