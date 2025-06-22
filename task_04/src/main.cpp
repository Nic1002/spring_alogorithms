#include <iostream>
#include <vector>

#include "fish.h"

int main() {
  int N, K;
  std::cin >> N >> K;

  std::vector<int> prices(N);
  for (int i = 0; i < N; i++) {
    std::cin >> prices[i];
  }

  long long result = SolveFishShopping(prices, K);
  std::cout << result << std::endl;

  return 0;
}