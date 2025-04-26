#include <iostream>
#include <vector>
#include "topology_sort.hpp"

int main(){
    std::vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> result = topology_sort(temps);
    // Результат: {1, 1, 4, 2, 1, 1, 0, 0}

    for (int i{0}; i < result.size(); ++i){
        std::cout << result[i] << " ";
    }
}