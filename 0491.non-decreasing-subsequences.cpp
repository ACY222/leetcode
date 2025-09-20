// @leet start
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
private:
    set<vector<int>> res;
    // the array should have at least two elements
    void backtrack(const vector<int>& nums,
                   vector<int>& path, int index) {
        if (index == nums.size()) {
            if (path.size() >= 2) {
                res.insert(path);
            }
            return;
        }
        // if path is empty, or the current number is greater than the last one
        // the case with nums[start]
        if (path.empty() or nums[index] >= path.back()) {
            path.push_back(nums[index]);
            backtrack(nums, path, index + 1);
            path.pop_back();
        }
        backtrack(nums, path,  index + 1);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        backtrack(nums, path, 0);
        return {res.begin(), res.end()};
    }
};
// @leet end
