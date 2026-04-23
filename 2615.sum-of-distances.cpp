// @leet start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, vector<int>> groups;
        vector<long long> dist(size);

        for (int i = 0; i < size; ++i) {
            groups[nums[i]].push_back(i);
        }

        for (auto& [_val, indices] : groups) {
            int n = indices.size();
            long long curr_sum = 0;

            for (int i = 1; i < n; ++i) {
                curr_sum += indices[i] - indices[0];
            }

            dist[indices[0]] = curr_sum;

            for (int i = 1; i < n; ++i) {
                long long delta = indices[i] - indices[i - 1];

                curr_sum += (2 * i - n) * delta;
                dist[indices[i]] = curr_sum;
            }
        }

        return dist;
    }
};
// @leet end
