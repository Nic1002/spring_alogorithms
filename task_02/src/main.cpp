#include <vector>
#include <iostream>
#include <stdexcept>

struct Stack {
    std::vector<int> arr; 

    // Добавляем элемент в стек
    void push(int element) {
        arr.push_back(element);
    }

    // Удаляем верхний элемент стека
    void pop() {
        if (arr.empty()) {
            throw std::out_of_range("Stack is empty. Cannot pop.");
        }
        arr.pop_back();
    }

    // Возвращаем верхний элемент стека
    int peek() const {
        if (arr.empty()) {
            throw std::out_of_range("Stack is empty. Cannot peek.");
        }
        return arr.back();
    }

    // Выводим весь стек
    void display() const {
        if (arr.empty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        for (int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    void min(){
        min_el = arr.min_element();
    }
};



int main() { 
    Stack stack;
    stack.push(2);
    stack.push(1);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(7);

    stack.display();
    std::cout << "\n";

    stack.pop();
    stack.display();
    std::cout << "\n";

    int a = stack.peek();
    std::cout << a;
    std::cout << "\n";


    return 0; 
}
