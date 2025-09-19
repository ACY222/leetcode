// @leet start
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
private:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, vector<int>& path, int start, int target) {
        if (target == 0) {  // if the sum == target, push path into res
            res.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            // if current num > remaining target, skip the last numbers
            if (nums[i] > target) {
                break;
            }
            path.push_back(nums[i]);
            backtrack(nums, path, i, target - nums[i]);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, path, 0, target);
        return res;
    }
};
// @leet end
