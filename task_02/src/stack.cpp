#include "stack.hpp"

class MyStack {
 private:
  int* data;
  int capacity;
  int topIndex;

  void resize() {
    int newCapacity = capacity * 2;
    int* newData = new int[newCapacity];
    for (int i = 0; i <= topIndex; ++i) {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
  }

 public:
  MyStack() : capacity(10), topIndex(-1) { data = new int[capacity]; }

  ~MyStack() { delete[] data; }

  void push(int x) {
    if (topIndex == capacity - 1) {
      resize();
    }
    data[++topIndex] = x;
  }

  int pop() {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    }
    return data[topIndex--];
  }

  int top() const {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    }
    return data[topIndex];
  }

  bool empty() const { return topIndex == -1; }
};

class MinStack {
 private:
  MyStack dataStack;
  MyStack minStack;

 public:
  void push(int x) {
    dataStack.push(x);
    if (minStack.empty() || x <= minStack.top()) {
      minStack.push(x);
    }
  }

  int pop() {
    if (dataStack.empty()) {
      throw std::out_of_range("Stack is empty");
    }
    int x = dataStack.pop();
    if (x == minStack.top()) {
      minStack.pop();
    }
    return x;
  }

  int top() { return dataStack.top(); }

  bool empty() const { return dataStack.empty(); }

  int getMin() {
    if (minStack.empty()) {
      throw std::out_of_range("Stack is empty");
    }
    return minStack.top();
  }
};