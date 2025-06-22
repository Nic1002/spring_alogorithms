#include "tables.hpp"

class TableSorter {
private:
    int n, m;
    vector<vector<int>> pref;

public:
    TableSorter(const vector<vector<int>>& matrix) {
        n = matrix.size();
        if (n == 0) {
            m = 0;
            return;
        }
        m = matrix[0].size();
        pref.resize(m);

        if (n == 1) return; // Нет пар строк для сравнения

        for (int j = 0; j < m; j++) {
            vector<int> bad(n-1, 0);
            for (int i = 0; i < n-1; i++) {
                if (matrix[i][j] > matrix[i+1][j]) {
                    bad[i] = 1;
                }
            }
            pref[j] = vector<int>(n-1, 0);
            if (n-1 > 0) {
                pref[j][0] = bad[0];
                for (int i = 1; i < n-1; i++) {
                    pref[j][i] = pref[j][i-1] + bad[i];
                }
            }
        }
    };

    bool query(int l, int r) {
        if (l == r) return true;
        int L = l - 1;
        int R = r - 2;
        for (int j = 0; j < m; j++) {
            int violations = 0;
            if (L <= R) {
                if (L == 0) violations = pref[j][R];
                else violations = pref[j][R] - pref[j][L-1];
            }
            if (violations == 0) return true;
        }
        return false;
    };
};