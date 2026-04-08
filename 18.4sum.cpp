// @leet start
#include <algorithm>
#include <cstdint>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n {static_cast<int>(nums.size())};

        if (n < 4) { return {}; }
        vector<vector<int>> results;
        std::sort(nums.begin(), nums.end());

        for (int i {0}; i < n - 3; ++i) {
            if (i > 0 and nums[i] == nums[i - 1]) { continue; }

            if ((int64_t)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]
                > target)
                break;
            if ((int64_t)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3]
                < target)
                continue;

            for (int j {i + 1}; j < n - 2; ++j) {
                if (j > i + 1 and nums[j] == nums[j - 1]) { continue; }

                if ((int64_t)nums[i] + nums[j] + nums[j + 1] + nums[j + 2]
                    > target)
                    break;
                if ((int64_t)nums[i] + nums[j] + nums[n - 1] + nums[n - 2]
                    < target)
                    continue;

                auto orig_sum {static_cast<int64_t>(nums[i] + nums[j])};
                auto left {j + 1};
                auto right {static_cast<int>(n - 1)};

                while (left < right) {
                    int64_t curr_sum = nums[left] + nums[right];
                    curr_sum += orig_sum;

                    if (curr_sum < target) {
                        ++left;
                    } else if (curr_sum > target) {
                        --right;
                    } else {
                        results.push_back({nums[i], nums[j], nums[left],
                                           nums[right]});
                        // skip duplicate values
                        while (left < right and nums[left] == nums[left + 1]) {
                            ++left;
                        }
                        while (left < right
                               and nums[right] == nums[right - 1]) {
                            --right;
                        }
                        ++left;
                        --right;
                    }
                }
            }
        }

        return results;
    }
};
// @leet end
