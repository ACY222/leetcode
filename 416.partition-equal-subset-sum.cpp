// @leet start
#include <vector>
using namespace std;
class Solution {
private:
    int sum = 0, n;

    void get_sum(const vector<int>& nums) {
        for (const int& num : nums) {
            sum += num;
        }
    }

    bool dp(const vector<int>& nums, int index, int left) {
        // if the sum of the selected part is greater than sum/2
        if (left < 0) {
            return false;
        }
        // if we have reached the end, check if the left == 0
        if (index == n) {
            return left == 0;
        }
        // keep going forward
        if (dp(nums, index + 1, left - nums[index]) or
            dp(nums, index + 1, left)) {
            return true;
        }
        return false;
    }

public:
    // we have two bags, and each time we determine if we should put the
    // current item into the bag
    bool canPartition(vector<int>& nums) {
        this->n = nums.size();
        get_sum(nums);
        // if the sum is odd, we can never partition
        if (sum % 2 == 1) {
            return false;
        }
        return dp(nums, 0, sum / 2);
    }
};
// @leet end
