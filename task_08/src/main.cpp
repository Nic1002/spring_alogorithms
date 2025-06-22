#include <iostream>

#include "hashmap.hpp"

int main() {
  HashMap map;

  // Вставка элементов
  map.insert("apple", 10);
  map.insert("banana", 20);
  map.insert("orange", 30);

  // Проверка наличия ключей
  std::cout << "Contains 'apple': " << map.contains("apple") << "\n";
  std::cout << "Contains 'grape': " << map.contains("grape") << "\n";

  // Получение значений
  std::cout << "Value of 'banana': " << map.get("banana") << "\n";

  // Удаление элемента
  map.remove("apple");
  std::cout << "After remove, contains 'apple': " << map.contains("apple")
            << "\n";

  // Размер таблицы
  std::cout << "Size: " << map.getSize() << "\n";

  return 0;
}