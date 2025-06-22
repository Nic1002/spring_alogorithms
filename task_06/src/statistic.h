#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

void SwapElements(int& a, int& b);

int Partition(vector<int>& arr, int left, int right);

int QuickSelect(vector<int>& arr, int left, int right, int k);

int KthOrderStatistic(vector<int> arr, int k);