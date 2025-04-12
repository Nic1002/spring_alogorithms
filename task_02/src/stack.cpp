// #include "stack.hpp"

// #include <exception>
// #include <stdexcept>

// template <typename T>
// void Stack<T>::push(T value) { data_.push_back(value); }

// int Stack<T>::pop() {
//   int result = data_.back();
//   data_.pop_back();
//   return result;
// }

// void MinStack::push(int value) {
//   data_.push_back(value);
//   if(data_mins.size() == 0 || value <= data_mins.back()){
//     data_mins.push_back(value);
//   } else{
//     data_mins.push_back(data_mins.back());
//   }
// }

// int MinStack::pop() {
//   auto result = data_.back();
//   data_.pop_back();
//   data_mins.pop_back();
//   return result;
// }

// int MinStack::getmin() {
//   if(data_mins.size() == 0){
//     throw std::runtime_error("Пустой стек - нет минимума");
//   }
//   return data_mins.back();
// }