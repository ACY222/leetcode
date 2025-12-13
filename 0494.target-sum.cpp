// @leet start
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    // sum(P) + sum(N) = sum
    // sum(P) - sum(N) = target
    // therefore, sum(P) = (sum + target) / 2
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum < target or (sum + target) % 2 != 0) {
            return 0;
        }

        // convert the problem into a 0-1 backpack problem
        int bag_size = (sum + target) / 2;
        if (bag_size < 0) {
            return 0;
        }

        vector<int> dp(bag_size + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int i = bag_size; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }

        return dp[bag_size];
    }
};
// @leet end
