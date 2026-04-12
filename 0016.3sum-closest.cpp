// @leet start
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        auto min_distance {numeric_limits<int>::max()};
        auto best_sum {0};

        sort(nums.begin(), nums.end());

        for (auto base_idx {0}; base_idx < nums.size() - 2; base_idx++) {
            auto left {base_idx + 1};
            auto right {nums.size() - 1};
            auto curr_sum {0};

            while (left < right) {
                curr_sum = nums[base_idx] + nums[left] + nums[right];

                auto curr_distance {abs(curr_sum - target)};
                if (curr_distance < min_distance) {
                    best_sum = curr_sum;
                    min_distance = curr_distance;
                }

                if (curr_sum < target) {
                    ++left;
                } else if (curr_sum > target) {
                    --right;
                } else {
                    return best_sum;
                }
            }
        }

        return best_sum;
    }
};
// @leet end
