// @leet start
#include <bitset>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum { accumulate(nums.begin(), nums.end(), 0) };
        if (sum %  2 != 0) {
            return false;
        }

        bitset<10001> bits(1);
        for (auto num : nums) {
            // get the possible number we can add to
            bits = bits | (bits << num);
            if (bits[sum / 2]) {
                return true;
            }
        }
        return false;
    }
};
// @leet end
