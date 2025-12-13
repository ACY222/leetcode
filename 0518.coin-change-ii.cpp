// @leet start
#include <vector>
using namespace std;

class Solution {
public:
    unsigned long long change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (const int& coin : coins) {
            for (int j = coin; j <= amount; ++j) {
                // dp[i][j] = dp[i - 1][j] + dp[i][j - coin]
                dp[j] = dp[j] + dp[j - coin];
            }
        }
        return dp[amount];
    }
};
// @leet end
