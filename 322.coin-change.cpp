// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
private:
    vector<int> nums;

    int dp(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return -1;
        }
        // check nums to avoid repeating calculations
        if (nums[amount] != -1) {
            return nums[amount];
        }

        int res = amount + 1;
        for (const int coin : coins) {
            int subProblem = dp(coins, amount - coin);
            if (subProblem == -1) {
                continue;
            }
            res = min(res, 1 + subProblem);
        }
        nums[amount] = (res == amount + 1) ? -1 : res;
        return nums[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        nums.resize(amount + 1, -1);
        return dp(coins, amount);
    }
};
// @leet end
