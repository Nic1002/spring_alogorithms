#pragma once

#include <vector>

class Stack {
 private:
  std::vector<int> arr;
  std::vector<int> min_stack;

 public:
  void Push(int element);

  void pop();

  int peek();

  void display();

  int min();

  bool isEmpty() const { return arr.empty(); }

  size_t size() const { return arr.size(); }
};
