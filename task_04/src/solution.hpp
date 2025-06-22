#include <deque>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

inline vector<pair<int, int>> BFish(const vector<int>& prices, int k) {
    vector<pair<int, int>> purchases;
    deque<int> dq;
    int n = prices.size();

    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && prices[i] <= prices[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= k - 1) {
            int buy_day = dq.front();
            if (purchases.empty() || purchases.back().first != buy_day) {
                purchases.emplace_back(buy_day, buy_day);
            } else {
                purchases.back().second++;
            }
        }
    }

    if (n < k) {
        if (!prices.empty()) {
            int min_pos = min_element(prices.begin(), prices.end()) - prices.begin();
            return {{min_pos, n - 1}};
        }
        return {};
    }

    return purchases;
}