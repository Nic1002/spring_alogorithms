#include <iostream>

#include "tree.hpp"

static void printTreeInfo(const BinarySearchTree& bst) {
  std::cout << "Tree size: " << bst.size() << "\n";
  std::cout << "Min value: "
            << (bst.isEmpty() ? "N/A" : std::to_string(bst.minValue()))
            << "\n";
  std::cout << "Is empty: " << (bst.isEmpty() ? "true" : "false") << "\n"
            << "\n";
}

int main() {
  BinarySearchTree bst;

  std::cout << "=== Initial empty tree ===" << "\n";
  printTreeInfo(bst);

  // Вставка элементов
  std::cout << "=== After inserting elements ===" << "\n";
  bst.insert(50);
  bst.insert(30);
  bst.insert(70);
  bst.insert(20);
  bst.insert(40);
  bst.insert(60);
  bst.insert(80);
  printTreeInfo(bst);

  // Проверка наличия элементов
  std::cout << "=== Checking contains ===" << "\n";
  std::cout << "Contains 30: " << (bst.contains(30) ? "true" : "false")
            << "\n";
  std::cout << "Contains 45: " << (bst.contains(45) ? "true" : "false")
            << "\n";
  std::cout << "Contains 70: " << (bst.contains(70) ? "true" : "false")
            << "\n"
            << "\n";

  // Удаление элементов
  std::cout << "=== After removing 30 and 70 ===" << "\n";
  bst.remove(30);
  bst.remove(70);
  printTreeInfo(bst);

  // Проверка после удаления
  std::cout << "=== Checking after removal ===" << "\n";
  std::cout << "Contains 30: " << (bst.contains(30) ? "true" : "false")
            << "\n";
  std::cout << "Contains 70: " << (bst.contains(70) ? "true" : "false")
            << "\n"
            << "\n";

  // Очистка дерева
  std::cout << "=== After clearing tree ===" << "\n";
  bst.clear();
  printTreeInfo(bst);

  // Попытка получить минимальное значение пустого дерева
  try {
    std::cout << "Trying to get min value from empty tree..." << "\n";
    bst.minValue();
  } catch (const std::runtime_error& e) {
    std::cout << "Error: " << e.what() << "\n";
  }

  return 0;
}