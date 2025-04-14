#include "q_sort.hpp"
#include <cstdlib>
#include <algorithm>

int partition(std::vector<int> &arr, int low, int high) 
{
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    
    std::swap(arr[pivotIndex], arr[high]);
    
    int i = low; // Указатель на место для следующего меньшего элемента
    
    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    // Возвращаем опорный элемент на правильную позицию
    std::swap(arr[i], arr[high]);
    return i;
}

void q_sort(std::vector<int> &arr, int low, int high) 
{
    if (low < high) 
    {
        // pi - индекс разделения, arr[pi] теперь на правильном месте
        int pi = partition(arr, low, high);

        q_sort(arr, low, pi - 1);
        q_sort(arr, pi + 1, high);
    }
}

void q_sort_new(std::vector<int> &arr) 
{
    q_sort(arr, 0, arr.size() - 1);
}
