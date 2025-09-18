// @leet start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> results;
    vector<bool> used;

    void backtrack(const vector<int>& nums, vector<int>& path) {
        if (path.size() == nums.size()) {
            results.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            // if the last number is same to current and not used
            if (i > 0 and nums[i - 1] == nums[i] and !used[i - 1]) {
                continue;
            }
            //
            used[i] = true;
            path.push_back(nums[i]);

            backtrack(nums, path);

            used[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size());
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtrack(nums, path);
        return results;
    }
};
// @leet end
