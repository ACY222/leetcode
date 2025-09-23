// @leet start
#include <vector>
using namespace std;

class Solution {
private:
    int count = 0;

    void dp(vector<int>& coins, int index, int amount) {
        if (amount == 0) {
            ++count;
        }
        // if we cannot make up the amount, return false
        if(index >= coins.size() or amount < coins[index]) {
            return;
        }

        for (int i = 0; i <= amount / coins[index]; ++i) {
            dp(coins, index + 1, amount - coins[index] * i);
        }
    }

public:
    int change(int amount, vector<int>& coins) {
        dp(coins, 0, amount);
        return count;
    }
};
// @leet end
