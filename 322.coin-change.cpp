// @leet start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    // nums[i] is the number of coins we need to make up i
    vector<int> nums;

    void dp(vector<int>& coins, int amount) {
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin > i) {
                    continue;
                }
                nums[i] = min(nums[i], nums[i - coin] + 1);
            }
        }
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        nums.resize(amount + 1, amount + 1);
        nums[0] = 0;

        dp(coins, amount);

        return nums[amount] == amount + 1 ? -1 : nums[amount];
    }
};
// @leet end
