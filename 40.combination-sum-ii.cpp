// @leet start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, vector<int>& path, int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] > target) {
                return;
            }

            // This is the most important part of this problem
            // if current num == last num, and last num is not used, then just
            // skip. It avoids duplicated path and saves a lot of time by
            // pruning in advance
            if (i > start and nums[i] == nums[i - 1]) {
                continue;
            }

            path.push_back(nums[i]);
            backtrack(nums, path, i + 1, target - nums[i]);
            path.pop_back();
        }
    }
public:
    // this problem is quite similar to last one
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, path, 0, target);
        return res;
    }
};
// @leet end
