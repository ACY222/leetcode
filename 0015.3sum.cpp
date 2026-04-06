// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());

        for (auto target_idx{0}; target_idx < nums.size() - 2; ++target_idx) {
            if (target_idx > 0 and nums[target_idx] == nums[target_idx - 1]) {
                continue;
            }

            if (nums[target_idx] + nums[target_idx + 1] + nums[target_idx + 2]
                > 0) {
                break;
            }

            auto target{-nums[target_idx]};

            auto left{target_idx + 1};
            auto right{nums.size() - 1};

            while (left < right) {
                auto sum{nums[left] + nums[right]};

                if (sum == target) {
                    results.emplace_back(
                        vector<int>{-target, nums[left], nums[right]});
                    while (left < right and nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    while (left < right and nums[right] == nums[right - 1]) {
                        --right;
                    }
                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return results;
    }
};
// @leet end
