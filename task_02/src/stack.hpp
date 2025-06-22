#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <vector>

class Stack {
 private:
  std::vector<int> data;

 public:
  void Push(int value) { data.push_back(value); }

  void Pop() {
    if (IsEmpty()) {
      throw std::runtime_error("Stack is empty");
    }
    data.pop_back();
  }

  int Top() {
    if (IsEmpty()) {
      throw std::runtime_error("Stack is empty");
    }
    return data.back();
  }

  bool IsEmpty() { return data.empty(); }
};


class MinStack {
 private:
  std::vector<int> stack;
  std::vector<int> minStack;

 public:
  void Push(int value) {
    stack.push_back(value);
    if (minStack.empty() || value <= minStack.back()) {
      minStack.push_back(value);
    }
  }

  void Pop() {
    if (stack.empty()) {
      throw std::runtime_error("Stack is empty");
    }
    if (stack.back() == minStack.back()) {
      minStack.pop_back();
    }
    stack.pop_back();
  }

  int Top() {
    if (stack.empty()) {
      throw std::runtime_error("Stack is empty");
    }
    return stack.back();
  }

  int FindMin() {
    if (minStack.empty()) {
      throw std::runtime_error("Stack is empty");
    }
    return minStack.back();
  }

  bool isEmpty() { return stack.empty(); }
};

#endif  // STACK_H