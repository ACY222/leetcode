// @leet start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], currSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currSum = nums[i] + (currSum > 0 ? currSum : 0);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
// @leet end
