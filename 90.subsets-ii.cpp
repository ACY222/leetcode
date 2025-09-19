// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;

    void backtrack(const vector<int>& nums, vector<int>& path,
                   int start) {
        if (start == nums.size()) {
            res.push_back(path);
            return;
        }

        path.push_back(nums[start]);
        backtrack(nums, path, start + 1);
        path.pop_back();

        while (start + 1 < nums.size() and nums[start] == nums[start + 1]) {
            ++start;
        }
        backtrack(nums, path, start + 1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        sort(nums.begin(), nums.end());

        backtrack(nums, path, 0);
        return res;
    }
};
// @leet end
