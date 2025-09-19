// @leet start
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;

    void backtrack(const vector<int>& nums, vector<int>& path, int start) {
        res.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtrack(nums, path, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        backtrack(nums, path, 0);
        return res;
    }
};
// @leet end
