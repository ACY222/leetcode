// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), count = 0;
        for (int i = 0; i < n - 2; ++i) {
            int last_idx = 0;
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = max(j + 1, last_idx); k < n; ++k) {
                    if (nums[i] + nums[j] <= nums[k]) {
                        count += (k - j - 1);
                        last_idx = k;
                        break;
                    } else if (k == n - 1) {
                        count += (k - j);
                    }
                }
            }
        }

        return count;
    }
};
// @leet end
