#pragma once 
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

inline int Partition(vector<int> ar, int l, int r) {
  int v = ar[(l + r) / 2];
  int i = l;
  int j = r;
  while (i <= j) {
    while (ar[i] < v) {
      i++;
    }
    while (ar[j] > v) {
      j--;
    }
    if (i >= j) {
      break;
    }
    swap(ar[i++], ar[j--]);
  }
  return j;
}

inline int FindOrderStat(vector<int> arr, int k) {
    if (arr.empty() || k < 0 || k >= arr.size()) {
      
        throw out_of_range("Invalid k value or empty array");
    }
    
    int l = 0, r = arr.size();
    while (true) {
        int m = Partition(arr, l, r);

        if (m == k) {
            return arr[m];
        }
        else if (k < m) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }
}