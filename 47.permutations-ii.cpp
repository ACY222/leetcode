// @leet start
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    vector<bool> visited;

    void backtrack(const vector<int>& nums, vector<int>&path, int count) {
        if (count == 0) {
            res.push_back(path);
            return;
        }

        // avoid using the same value more than once in the same layer
        unordered_set<int> used;
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] or used.count(nums[i])) {
                continue;
            }
            used.insert(nums[i]);
            path.push_back(nums[i]);
            visited[i] = true;

            backtrack(nums, path, count - 1);
            path.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visited.resize(nums.size());
        vector<int> path;
        backtrack(nums, path, nums.size());
        return res;
    }
};
// @leet end
