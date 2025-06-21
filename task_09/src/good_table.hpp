#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

class SortedTableChecker {
  int n, m;
  std::vector<std::vector<int>> a;
  std::vector<int> maxReachForRow;

 public:
  SortedTableChecker(const std::vector<std::vector<int>>& table);

  void preprocess();

  bool isSortedSegment(int l, int r) const;
};
