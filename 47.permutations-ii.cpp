// @leet start
#include <vector>
using namespace std;

class Solution {
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int start) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        // swap nums
        for (int i = start; i < nums.size(); ++i) {
            // skip repeated numbers
            if (i > start && nums[i] == nums[start]) continue;
            swap(nums[start], nums[i]);
            backtrack(res, nums, start + 1);

        }
        // which is right the reverse operations of the last loop
        // elegant!
        for (int i = nums.size() - 1; i > start; --i) {
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        backtrack(res, nums, 0);
        return res;
    }
};
// @leet end
