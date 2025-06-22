#include "tree.hpp"
#include <iostream>

void printTreeInfo(const BinarySearchTree& bst) {
    std::cout << "Tree size: " << bst.size() << std::endl;
    std::cout << "Min value: " << (bst.isEmpty() ? "N/A" : std::to_string(bst.minValue())) << std::endl;
    std::cout << "Is empty: " << (bst.isEmpty() ? "true" : "false") << std::endl << std::endl;
}

int main() {
    BinarySearchTree bst;
    
    std::cout << "=== Initial empty tree ===" << std::endl;
    printTreeInfo(bst);

    // Вставка элементов
    std::cout << "=== After inserting elements ===" << std::endl;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    printTreeInfo(bst);

    // Проверка наличия элементов
    std::cout << "=== Checking contains ===" << std::endl;
    std::cout << "Contains 30: " << (bst.contains(30) ? "true" : "false") << std::endl;
    std::cout << "Contains 45: " << (bst.contains(45) ? "true" : "false") << std::endl;
    std::cout << "Contains 70: " << (bst.contains(70) ? "true" : "false") << std::endl << std::endl;

    // Удаление элементов
    std::cout << "=== After removing 30 and 70 ===" << std::endl;
    bst.remove(30);
    bst.remove(70);
    printTreeInfo(bst);

    // Проверка после удаления
    std::cout << "=== Checking after removal ===" << std::endl;
    std::cout << "Contains 30: " << (bst.contains(30) ? "true" : "false") << std::endl;
    std::cout << "Contains 70: " << (bst.contains(70) ? "true" : "false") << std::endl << std::endl;

    // Очистка дерева
    std::cout << "=== After clearing tree ===" << std::endl;
    bst.clear();
    printTreeInfo(bst);

    // Попытка получить минимальное значение пустого дерева
    try {
        std::cout << "Trying to get min value from empty tree..." << std::endl;
        bst.minValue();
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}