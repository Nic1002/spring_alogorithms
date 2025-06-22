#pragma once
#include <vector>
#include <stack>

using namespace std;

inline vector<int> DailyTemp(const vector<int>& temp){
  int n = temp.size();
  vector<int> res(n, 0);
  stack<int> s;

  for(int i = 0; i<n; ++i)
  {
    while(!s.empty() && temp[i]>temp[s.top()])
    {
      int prev_d = s.top();
      s.pop();
      res[prev_d] = i - prev_d;
    }
    s.push(i);
  }
  return res;
}