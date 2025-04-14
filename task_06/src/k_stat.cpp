#include "k_stat.hpp"

#include <iostream>
#include <cstdlib>
#include <algorithm>


int partition(std::vector<int>& arr, int left, int right) 
{
    int pivotIndex = left + rand() % (right - left + 1);
    int pivotValue = arr[pivotIndex];
    
    std::swap(arr[pivotIndex], arr[right]);
    
    int storeIndex = left;
    for (int i = left; i < right; i++) 
    {
        if (arr[i] < pivotValue) 
        {
            std::swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    
    std::swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

int quick_select(std::vector<int> &arr, int left, int right, int k) 
{
    if (left == right) 
        return arr[left];
    
    int pivotIndex = partition(arr, left, right);
    
    if (k == pivotIndex)
        return arr[k];
    else if (k < pivotIndex)
        return quick_select(arr, left, pivotIndex - 1, k);
    else
        return quick_select(arr, pivotIndex + 1, right, k);
}

int find_k_stat(std::vector<int>& arr, int n) 
{
    if (n < 0 || n >= arr.size()) 
    {
        std::cerr << "Invalid n: out of bounds!" << std::endl;
        return -1;
    }
    return quick_select(arr, 0, arr.size() - 1, n);
}