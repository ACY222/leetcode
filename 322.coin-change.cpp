// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
private:
    // nums of coins needed to make up amount
    vector<int> nums;

    void dp(vector<int>& coins, int amount) {
        nums[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (const int coin : coins) {
                if (i - coin < 0) {
                    continue;
                }
                nums[i] = min(nums[i], 1 + nums[i - coin]);
            }
        }
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        nums.resize(amount + 1, amount + 1);
        dp(coins, amount);
        return nums[amount] == amount + 1 ? -1 : nums[amount];

    }
};
// @leet end
