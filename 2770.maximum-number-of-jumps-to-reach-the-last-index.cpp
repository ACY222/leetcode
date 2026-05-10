// @leet start
#include <vector>
using namespace std;
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size(), max_jumps = -1, count = 1;
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 0; i < n - 1; ++i) {
            // this index is irreacheable
            if (dp[i] == -1) { continue; }

            for (int j = i + 1; j < n; ++j) {
                if (abs(nums[i] - nums[j]) <= target and dp[i] >= dp[j]) {
                    dp[j] = dp[i] + 1;
                }
            }
        }

        return dp.back();
    }
};
// @leet end
