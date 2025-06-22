#include "stack.hpp"

#include <vector>
#include <stdexcept>
#include <iostream>

void Stack::Push(int element) {
    arr.push_back(element);
    if (min_stack.empty() || element <= min_stack.back()) {
        min_stack.push_back(element);
    }
}

void Stack::pop() {
    if (arr.empty()) {
        throw std::out_of_range("Stack is empty. Cannot pop.");
    }
    if (arr.back() == min_stack.back()) {
        min_stack.pop_back();
    }
    arr.pop_back();
}

int Stack::peek() {
    if (arr.empty()) {
        throw std::out_of_range("Stack is empty. Cannot peek.");
    }
    return arr.back();
}

void Stack::display() {
    if (arr.empty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int Stack::min() {
    if (arr.empty()) {
        throw std::out_of_range("Stack is empty. Cannot find min.");
    }
    return min_stack.back();
}