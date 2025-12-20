// @leet start
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        static const int factorial[7] = {0, 1, 2, 6, 24, 120, 720};
        vector<vector<int>> res;
        res.reserve(factorial[nums.size()]);
        backtrack(nums, 0, res);
        return res;
    }
};
// @leet end
