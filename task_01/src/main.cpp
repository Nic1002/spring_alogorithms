#include "function.h"

int main() {
    int n;
    std::cin >> n;
    
    int count;
    std::cin >> count;
    
    std::vector<int> list(count);
    for (int i = 0; i < count; i++) {
        std::cin >> list[i];
    }
    
    auto result = Numbers(n, list);
    std::cout << result.first << std::endl;
    std::cout << result.second << std::endl;
    
    return 0;
}