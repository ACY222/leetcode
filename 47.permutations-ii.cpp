// @leet start
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> results;

    void backtrack(vector<int>& nums, int start) {
        if (start == nums.size()) {
            for (auto& res : results) {
                if (res == nums) {
                    return;
                }
            }
            results.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            // just swap the numbers that are different or stay in place
            if (i != start and nums[i] == nums[start]) {
                continue;
            }
            swap(nums[i], nums[start]);
            backtrack(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return results;
    }
};
// @leet end
