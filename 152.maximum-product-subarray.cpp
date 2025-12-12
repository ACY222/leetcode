// @leet start
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

struct Node {
    int min;
    int max;

    Node() : min(0), max(0) {}
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<Node> dp(nums.size());
        int max_val = INT_MIN;

        dp[0].max = nums[0];
        dp[0].min = nums[0];
        max_val = max(max_val, dp[0].max);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                dp[i].max = max(nums[i], nums[i] * dp[i - 1].max);
                dp[i].min = min(nums[i], nums[i] * dp[i - 1].min);
            }
            else {
                dp[i].max = max(nums[i], nums[i] * dp[i - 1].min);
                dp[i].min = min(nums[i], nums[i] * dp[i - 1].max);
            }
            max_val = max(max_val, dp[i].max);
        }
        return max_val;
    }
};
// @leet end
