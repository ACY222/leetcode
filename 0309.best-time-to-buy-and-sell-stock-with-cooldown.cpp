// @leet start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // there are three states: canBuy, canSell, cooldown
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> can_buy(n), can_sell(n), cooldown(n);
        // initialization
        can_buy[0] = 0;
        can_sell[0] = -prices[0];
        cooldown[0] = INT_MIN;

        for (int i = 1; i < n; ++i) {
            // do nothing
            can_buy[i] = max(can_buy[i - 1], cooldown[i - 1]);
            // do nothing or buy it today
            can_sell[i] = max(can_sell[i - 1], can_buy[i - 1] - prices[i]);
            // sell it today
            cooldown[i] = can_sell[i - 1] + prices[i];
        }
        return max(can_buy[n - 1], cooldown[n - 1]);
    }
};
// @leet end
