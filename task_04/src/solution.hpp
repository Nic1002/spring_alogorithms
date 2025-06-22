#include <deque>
#include <utility>
#include <vector>

using namespace std;

inline vector<pair<int, int>> BFish(const vector<int>& prices, int k) {
    int n = prices.size();
    vector<pair<int, int>> purchases;
    deque<int> dq;

    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && prices[i] <= prices[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if (dq.front() == i) { 
            int buy_day = i;
            int sell_day = min(i + k - 1, n - 1);
            purchases.emplace_back(buy_day, sell_day);
        }
    }
    return purchases;
}