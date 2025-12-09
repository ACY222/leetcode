#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    // using dynamic programming
    int rob(vector<int>& nums) {
        // dp[i] is the maximum amount of money you can rob
        // when robbing the i-th house
        if (nums.size() <= 2) {
            return *max_element(nums.begin(), nums.end());
        }
        else if (nums.size() == 3) {
            return max(nums[0] + nums[2], nums[1]);
        }
        array<int, 4> dp = {nums[0], nums[1], nums[0] + nums[2], 0};
        int index = 0;
        for (int i = 3; i < nums.size(); ++i) {
            int val0 = dp[index];
            int val1 = dp[(index + 1) & 3];     // == (index + 1) % 4;

            int write_pos = (index + 3) & 3;
            dp[write_pos] = max(val0, val1) + nums[i];

            index = (index + 1) & 3;
        }
        return max(dp[(index + 2) & 3], dp[(index + 1) & 3]);
    }
};

int main() {
    Solution sol;
    vector<int> nums {1, 2, 3, 1};
    sol.rob(nums);
}