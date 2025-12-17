// @leet start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // there are three states: canBuy, canSell, cooldown
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> canBuy(n), canSell(n), cooldown(n);

        // initialization
        canBuy[0] = 0;
        canSell[0] = -prices[0];
        cooldown[0] = INT_MIN;

        for (int i = 1; i < n; ++i) {
            canBuy[i] = max(canBuy[i - 1], cooldown[i - 1]);
            canSell[i] = max(canBuy[i - 1] - prices[i], canSell[i - 1]);
            cooldown[i] = canSell[i - 1] + prices[i];
        }
        return max(canBuy[n - 1], cooldown[n - 1]);
    }
};
// @leet end
