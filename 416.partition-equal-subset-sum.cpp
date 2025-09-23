// @leet start
#include <bitset>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if (sum % 2 != 0) {
            return false;
        }

        // nums[i] <= 100, nums.size() <= 200
        // so sum <= 20000, target_sum = sum / 2 <= 10000
        // bits[i] == 1 means we can get i by adding some nums
        // and we can always get 0
        bitset<10001> bits(1);
        for (auto num : nums) {
            bits = bits | (bits << num);
            if (bits[sum / 2]) {
                return true;
            }
        }
        return false;
    }
};
// @leet end
