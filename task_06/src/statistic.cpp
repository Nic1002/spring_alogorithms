#include "statistic.hpp"

void SwapElements(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int Partition(std::vector<int>& arr, int left, int right) {
    int mid = left + (right - left) / 2;
    int pivot = arr[mid];
    SwapElements(arr[mid], arr[right]);
    
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            SwapElements(arr[i], arr[j]);
            i++;
        }
    }
    SwapElements(arr[i], arr[right]);
    return i;
}

int QuickSelect(std::vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }
    
    int pos = Partition(arr, left, right);
    
    if (k == pos) {
        return arr[k];
    } else if (k < pos) {
        return QuickSelect(arr, left, pos - 1, k);
    } else {
        return QuickSelect(arr, pos + 1, right, k);
    }
}

int KthOrderStatistic(std::vector<int> arr, int k) {
    if (arr.empty()) {
        throw std::invalid_argument("Array is empty");
    }
    if (k < 0 || k >= static_cast<int>(arr.size())) {
        throw std::out_of_range("k is out of array bounds");
    }
    
    return QuickSelect(arr, 0, arr.size() - 1, k);
}