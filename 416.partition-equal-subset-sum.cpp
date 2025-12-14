// @leet start
#include <numeric>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }

        bitset<10001> bits(1);   // dp[0] = 1
        for (int num : nums) {
            bits = bits | (bits << num);

            if (bits[sum / 2]) {
                return true;
            }
        }
        return false;
    }
};
// @leet end
