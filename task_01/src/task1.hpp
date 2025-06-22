#include <vector>
#include <stdexcept>

std::vector<int> FindNumberOfSumma(std::vector<int> vec, int summa) {
  if (vec.empty()) {
    throw std::runtime_error("Vector is empty");
  }
  int start_iterator{0};
  int end_iterator{vec.size() - 1};
  std::vector<int> return_vector;
  while (true) {
    if (vec[start_iterator] + vec[end_iterator] == summa) {
      return_vector.push_back(vec[start_iterator]);
      return_vector.push_back(vec[end_iterator]);
      return return_vector;
    }
    if (vec[start_iterator] + vec[end_iterator] < summa) {
      start_iterator++;
    }
    if (vec[start_iterator] + vec[end_iterator] > summa) {
      end_iterator--;
    }
    if (start_iterator == end_iterator) {
      throw std::runtime_error("Summa not found");
    }
  }
}