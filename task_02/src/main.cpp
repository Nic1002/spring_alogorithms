#include <iostream>

#include "stack.hpp"

int main() {
  Stack stack;
  stack.Push(2);
  stack.Push(1);
  stack.Push(3);
  stack.Push(4);
  stack.Push(5);
  stack.Push(7);

  stack.display();
  std::cout << "\n";

  stack.pop();
  stack.display();
  std::cout << "\n";

  int a = stack.peek();
  std::cout << a << "\n";

  int b = stack.min();
  std::cout << "minimal element: " << b;
  return 0;
}
