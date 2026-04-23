// @leet start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    struct indices_presum {
        int index;
        long long presum;

        indices_presum(int index, int presum) : index(index), presum(presum) {}
    };

public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dist(n, 0);
        unordered_map<int, vector<indices_presum>> val_to_indices_presum;

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            val_to_indices_presum[num].emplace_back(i, i);
        }

        for (auto& [_val, indices_presum] : val_to_indices_presum) {
            int size = indices_presum.size();
            for (int i = 1; i < size; ++i) {
                indices_presum[i].presum += indices_presum[i - 1].presum;
            }
        }

        for (auto& [_val, indices_presum] : val_to_indices_presum) {
            int size = indices_presum.size();

            // if the value is unique, leave it 0
            if (size == 1) { continue; }

            for (int i = 0; i < size; ++i) {
                // pre_sum_dist = (i - 0) * i - presum[i - 1]
                // post_sum_dist = (presum[size - 1] - presum[i + 1]) - (size -
                // 1 - (i + 1)) * i
                int index = indices_presum[i].index;
                long long pre_sum_dist = 0, post_sum_dist = 0;
                if (i > 0) {
                    pre_sum_dist =
                        (long long)i * index - indices_presum[i - 1].presum;
                }

                if (i < size - 1) {
                    post_sum_dist = (indices_presum[size - 1].presum
                                     - indices_presum[i].presum)
                                    - (long long)(size - 1 - i) * index;
                }

                dist[indices_presum[i].index] = pre_sum_dist + post_sum_dist;
            }
        }

        return dist;
    }
};
// @leet end
