#include <vector>

template <typename T>
class Stack {
 public:
  void Push(T k);
  T Pop();

 private:
  std ::vector<T> _data;
};

template <typename T>
void Stack<T>::Push(T k) {
  _data.push_back(k);
}

template <typename T>
T Stack<T>::Pop() {
  T pop_val{_data.back()};
  _data.pop_back();
  return pop_val;
}

template <typename T>
class MinStack {
 public:
  void Push(T k);
  T Pop();
  T GetMin();

 private:
  std ::vector<T> _data;
  std ::vector<T> _min_data;
};

template <typename T>
void MinStack<T>::Push(T k) {
  if (_min_data.size() == 0)
    _min_data.push_back(k);
  else if (_min_data.back() > k)
    _min_data.push_back(k);
  else
    _min_data.push_back(_min_data.back());
  _data.push_back(k);
}

template <typename T>
T MinStack<T>::Pop() {
  T pop_val{_data.back()};
  _data.pop_back();
  _min_data.pop_back();
  return pop_val;
}

template <typename T>
T MinStack<T>::GetMin() {
  return _min_data.back();
}

// #pragma once

// #include <stack>
// #include <vector>

// class Stack {
//  public:
//   void Push(int value);
//   int Pop();

//  private:
//   std::stack<int> data_;
// };

// class MinStack {
//  public:
//   void Push(int value);
//   int Pop();
//   int GetMin();

//  private:
//   std::vector<int> data_;
// };
