// @leet start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // Actually, this is the method for calculating the number of
    // multiplications in matrix multiplication.
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> new_nums(n);
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n - 2; ++i) {
            new_nums[i + 1] = nums[i];
        }
        new_nums[0] = 1; new_nums[n - 1] = 1;

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]
                                + new_nums[i] * new_nums[k] * new_nums[j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @leet end
