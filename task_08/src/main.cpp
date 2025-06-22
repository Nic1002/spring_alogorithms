#include "hashmap.hpp"
#include <iostream>

int main() {
    HashMap map;

    // Вставка элементов
    map.insert("apple", 10);
    map.insert("banana", 20);
    map.insert("orange", 30);

    // Проверка наличия ключей
    std::cout << "Contains 'apple': " << map.contains("apple") << std::endl;
    std::cout << "Contains 'grape': " << map.contains("grape") << std::endl;

    // Получение значений
    std::cout << "Value of 'banana': " << map.get("banana") << std::endl;

    // Удаление элемента
    map.remove("apple");
    std::cout << "After remove, contains 'apple': " << map.contains("apple") << std::endl;

    // Размер таблицы
    std::cout << "Size: " << map.getSize() << std::endl;

    return 0;
}