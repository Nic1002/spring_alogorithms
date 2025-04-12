#pragma once

#include <vector>
#include <stdexcept>



template <typename T>
class Stack {
  public:
  void push(T value) { data_.push_back(value); }
  T pop() {
    T result = data_.back();
    data_.pop_back();
    return result;
  }

 private:
  std::vector<T> data_;
};




template <typename T>
class MinStack {
 public:
  void push(T value) { 
    data_.push_back(value);
    if(data_mins.size() == 0 || value <= data_mins.back()){
      data_mins.push_back(value);
    } else{
      data_mins.push_back(data_mins.back());
    }
  }
  T pop() {
    T result = data_.back();
    data_.pop_back();
    data_mins.pop_back();
    return result;
  }
  
  T getmin() {
    if(data_mins.size() == 0){
      throw std::runtime_error("Пустой стек - нет минимума");
    }
    return data_mins.back(); 
  }

 private:
  std::vector<T> data_;
  std::vector<T> data_mins;
};
