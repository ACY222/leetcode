// @leet start
#include <algorithm>
#include <cstdint>
#include <vector>

using std::vector;

class Solution {
private:
    int left;
    int right;
    int64_t orig_sum;

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) { return {}; }
        vector<vector<int>> results;
        std::sort(nums.begin(), nums.end());

        for (auto i {0}; i < nums.size() - 3; ++i) {
            for (auto j {i + 1}; j < nums.size() - 2; ++j) {
                orig_sum = nums[i] + nums[j];
                left = j + 1;
                right = static_cast<int>(nums.size() - 1);

                while (left < right) {
                    int64_t curr_sum = nums[left] + nums[right];
                    curr_sum += orig_sum;

                    if (curr_sum < target) {
                        while (left < right and nums[left] == nums[left + 1]) {
                            ++left;
                        }
                        ++left;
                    } else if (curr_sum > target) {
                        while (left < right
                               and nums[right] == nums[right - 1]) {
                            --right;
                        }
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

                while (j < nums.size() - 2 and nums[j] == nums[j + 1]) {
                    ++j;
                }
            }
            while (i < nums.size() - 3 and nums[i] == nums[i + 1]) {
                ++i;
            }
        }

        return results;
    }
};
// @leet end
