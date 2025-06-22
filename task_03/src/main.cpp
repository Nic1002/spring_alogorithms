#include <iostream>
#include <vector>

#include "weather.h"

int main() {
  int n;
  std::cin >> n;

  std::vector<int> temperatures(n);
  for (int i = 0; i < n; i++) {
    std::cin >> temperatures[i];
  }

  auto result = DailyTemperatures(temperatures);
  for (int days : result) {
    std::cout << days << " ";
  }
  std::cout << std::endl;

  return 0;
}