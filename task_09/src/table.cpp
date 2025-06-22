#include "table.hpp"

void TableChecker::readTable(std::istream& in) {
    in >> n >> m;
    table.assign(n, std::vector<int>(m));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            in >> table[i][j];
        }
    }
    
    prepareData();
}

void TableChecker::prepareData() {
    column_ok.assign(m, std::vector<int>(n, 1)); // Initialize all as 1
    prefix.assign(m, std::vector<int>(n + 1, 0));
    
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n - 1; ++i) {
            if (table[i][j] > table[i + 1][j]) {
                column_ok[j][i] = 0; // Mark as not OK
            }
        }
        
        // Build prefix sum of violations
        for (int i = 0; i < n; ++i) {
            prefix[j][i + 1] = prefix[j][i] + (column_ok[j][i] == 0 ? 1 : 0);
        }
    }
}

bool TableChecker::isRangeSorted(int l, int r) const {
    if (l >= r) return true;
    
    for (int j = 0; j < m; ++j) {
        int violations = prefix[j][r] - prefix[j][l];
        if (violations == 0) {
            return true;
        }
    }
    return false;
}

void TableChecker::processQueries(std::istream& in, std::ostream& out) {
    int k;
    in >> k;
    
    while (k--) {
        int l, r;
        in >> l >> r;
        --l; // convert to 0-based
        
        out << (isRangeSorted(l, r - 1) ? "Yes" : "No") << '\n';
    }
}