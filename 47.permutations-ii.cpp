// @leet start
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, int start) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        // record the values used in current layer
        unordered_set<int> used_val;
        for (int i = start; i < nums.size(); ++i) {
            // skip used numbers
            if (used_val.count(nums[i])) {
                continue;
            }
            // skip if the number == current number
            if (i != start and nums[i] == nums[start]) {
                continue;
            }
            used_val.insert(nums[i]);
            swap(nums[i], nums[start]);
            backtrack(nums, start + 1);
            used_val.erase(nums[i]);
            swap(nums[i], nums[start]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};
// @leet end
