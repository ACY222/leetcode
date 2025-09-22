// @leet start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] = nums[i - 1] + nums[i];
        }
        // maxSub is the sum of the maximum subarray
        // minPre is the min of prefix sums
        int maxSub = nums[0], minPre = 0;
        for (int i = 0; i < nums.size(); ++i) {
            maxSub = max(maxSub, nums[i] - minPre);
            minPre = min(minPre, nums[i]);
        }
        return maxSub;
    }
};
// @leet end
