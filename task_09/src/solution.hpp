#pragma once

#include <vector>
#include <algorithm>

using namespace std;

inline vector<vector<bool>> ComputeColSorted(const vector<vector<int>>& table, int n, int m) {
    vector<vector<bool>> col_sorted(m, vector<bool>(n));
    for (int j = 0; j < m; ++j) {
        col_sorted[j][0] = true;
        for (int i = 1; i < n; ++i) {
            col_sorted[j][i] = col_sorted[j][i-1] && (table[i-1][j] <= table[i][j]);
        }
    }
    return col_sorted;
}

inline vector<vector<int>> ComputeSegmentStart(const vector<vector<int>>& table, int n, int m) {
    vector<vector<int>> segment_start(m, vector<int>(n));
    for (int j = 0; j < m; ++j) {
        segment_start[j][0] = 0;
        for (int i = 1; i < n; ++i) {
            if (table[i-1][j] <= table[i][j]) {
                segment_start[j][i] = segment_start[j][i-1];
            } else {
                segment_start[j][i] = i;
            }
        }
    }
    return segment_start;
}

inline vector<int> ComputeRowMaxGood(const vector<vector<int>>& segment_start, int n, int m) {
    vector<int> row_max_good(n);
    for (int i = 0; i < n; ++i) {
        int max_good = -1;
        for (int j = 0; j < m; ++j) {
            if (segment_start[j][i] <= i) {
                max_good = max(max_good, segment_start[j][i]);
            }
        }
        row_max_good[i] = max_good;
    }
    return row_max_good;
}

inline bool CanSort(const vector<int>& row_max_good, int l, int r) {
    if (l >= r) {
        return true;
    }
    return row_max_good[r] <= l;
}
