#include <vector>

using namespace std;

class Solution {
public:
    // using dynamic programming
    int rob(vector<int>& nums) {
        // dp[i] is the maximum amount of money you can rob
        // when robbing the i-th house
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 2) {
                dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
            }
            else if (i < 2) {
                dp[i] = nums[i];
            }
            else {  // i == 2
                dp[2] = nums[0] + nums[2];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};