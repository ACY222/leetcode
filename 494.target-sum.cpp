// @leet start
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        vector<vector<int>> results(nums.size());
        results[0].push_back(nums[0]);
        results[0].push_back(-nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            results[i].reserve(pow(2, i + 1));
            for (int sum : results[i - 1]) {
                results[i].push_back(sum + nums[i]);
                results[i].push_back(sum - nums[i]);
            }
        }

        for (int res : results.back()) {
            if (res == target) {
                ++count;
            }
        }
        return count;
    }
};
// @leet end
