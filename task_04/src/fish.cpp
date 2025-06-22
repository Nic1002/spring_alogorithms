#include "fish.h"

#include <stack>
#include <vector>

long long SolveFishShopping(const std::vector<int>& prices, int K) {
  int N = prices.size();
  if (N == 0) return 0;

  std::vector<int> next(N);
  std::stack<int> st;

  for (int i = 0; i < N; i++) {
    while (!st.empty()) {
      int j = st.top();
      if (j + K > i) break;
      next[j] = (j + K > N) ? N : j + K;
      st.pop();
    }

    while (!st.empty() && prices[st.top()] > prices[i]) {
      next[st.top()] = i;
      st.pop();
    }

    st.push(i);
  }

  while (!st.empty()) {
    int j = st.top();
    st.pop();
    next[j] = (j + K > N) ? N : j + K;
  }

  long long total_cost = 0;
  int i = 0;
  while (i < N) {
    int count = next[i] - i;
    total_cost += static_cast<long long>(prices[i]) * count;
    i = next[i];
  }

  return total_cost;
}