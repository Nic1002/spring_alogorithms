#pragma once 

#include <algorithm>
#include <cmath>
using namespace std;

template <typename type_ar> 
int Partition(type_ar *ar, int l, int r) {
  type_ar v = ar[(l + r) / 2];
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

template <typename type_arrr> 
void QuickSort(type_arrr *arrr, int l, int r) {
  if (l < r) {
    int q = Partition(arrr, l, r);
    QuickSort(arrr, l, q);
    QuickSort(arrr, q + 1, r);
  }
}
