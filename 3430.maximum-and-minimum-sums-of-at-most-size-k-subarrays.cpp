// @leet start
#include <deque>
#include <vector>
using namespace std;
class Solution {
public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();

        long long result = 0;
        deque<int> min_indices, max_indices;

        vector<int> counts(size, 2);
        for (int sub_size = 2; sub_size <= k; ++sub_size) {
            for (int idx = 0; idx < size; ++idx) {
                int curr_val = nums[idx];

                if (!min_indices.empty()
                    and min_indices.front() == idx - sub_size) {
                    min_indices.pop_front();
                }
                while (!min_indices.empty()
                       and curr_val < nums[min_indices.back()]) {
                    min_indices.pop_back();
                }
                min_indices.push_back(idx);

                if (!max_indices.empty()
                    and max_indices.front() == idx - sub_size) {
                    max_indices.pop_front();
                }

                while (!max_indices.empty()
                       and curr_val > nums[max_indices.back()]) {
                    max_indices.pop_back();
                }
                max_indices.push_back(idx);

                if (idx >= sub_size - 1) {
                    counts[max_indices.front()]++;
                    counts[min_indices.front()]++;
                }
            }
            min_indices.clear();
            max_indices.clear();
        }

        for (int i = 0; i < size; ++i) {
            result += static_cast<long long>(nums[i]) * counts[i];
        }

        return result;
    }
};
// @leet end
