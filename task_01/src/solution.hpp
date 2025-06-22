#pragma once 

#include <vector>
using namespace std;

struct Result 
{
  bool finded = false;
  int left = 0, right = 0;
};

inline Result Solve(int n, int c, const vector<int>& a)
{
  if (a.size() != n) return {};

  int left = 0;
  int right = n-1;
  while(left<right)
  {
    if (a[left]+a[right]<c) {++left; continue;}
    if (a[left]+a[right]>c) {--right; continue;}
    if (a[left]+a[right]==c) return {true, a[left], a[right]};
  }

  return {};
}

