#include <iostream>
#include "stack.hpp"
// #include "stack.cpp"

int main() {
    Stack<int> st {};
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(7);
    st.push(8);
    std::cout << st.pop() << " " << st.pop() << " " << st.pop() << " " << st.pop() << " ";
    st.push(0);
    std::cout << st.pop();

    MinStack<int> stm{};
    stm.push(5);
    stm.push(7);
    stm.push(3);
    stm.push(0);
    stm.push(1);
    stm.push(-2);
    std::cout << stm.getmin() << std::endl;
    std::cout << stm.pop() << " " << stm.getmin() << std::endl;
    std::cout << stm.pop() << " " << stm.getmin() << std::endl;
    std::cout << stm.pop() << " " << stm.getmin() << std::endl;
    std::cout << stm.pop() << " " << stm.getmin() << std::endl;
    std::cout << stm.pop() << " " << stm.getmin() << std::endl;
    std::cout << stm.pop() << " " ;
    // std::cout << stm.getmin() << stm.getmin() << stm.getmin();
    return 0; 
}
