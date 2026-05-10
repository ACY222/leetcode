// @leet start
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size(), max_jumps = -1, count = 1;
        unordered_set<int> from;

        from.insert(0);

        while (!from.empty()) {
            unordered_set<int> to;
            for (int i : from) {
                for (int j = i + 1; j < n; ++j) {
                    if (to.find(j) == to.end()
                        and abs(nums[j] - nums[i]) <= target) {
                        if (j == n - 1) { max_jumps = count; }

                        to.insert(j);
                    }
                }
            }

            from = std::move(to);
            ++count;
        }
        return max_jumps;
    }
};
// @leet end
//
// 1 2 1; 0
