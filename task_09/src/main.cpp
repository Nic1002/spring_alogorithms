#include <iostream>
#include <vector>
#include "solution.hpp"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> table[i][j];
        }
    }
    
    auto segment_start = ComputeSegmentStart(table, n, m);
    auto row_max_good = ComputeRowMaxGood(segment_start, n, m);
    
    int k;
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        
        if (CanSort(row_max_good, l, r)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}