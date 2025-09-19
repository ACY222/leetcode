// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, int start) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int index = start; index < nums.size(); ++index) {
            if (index > start and nums[index] == nums[start]) {
                continue;
            }

            swap(nums[index], nums[start]);
            backtrack(nums, start + 1); // why it's start + 1
        }

        // restore nums
        for (int index = nums.size() - 1; index > start; --index) {
            swap(nums[index], nums[start]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }
};
// @leet end
