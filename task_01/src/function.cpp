#include "function.hpp"

pair<int, int> Numbers(int number, std::vector<int> vec){
  int left = 0;
  int right = vec.size() - 1;
  while (left < right) {
    int sum = vec[left] + vec[right];
    if (sum == number) {
      return make_pair(vec[left], vec[right]);
    } 
    else if (sum < number) {
      left++;
    }
    else {
      right--;
    }
    throw runtime_error("These numbers weren't found");
  };
};