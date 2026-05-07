// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_max(n), suf_min(n);

        // initialize pre_max and suf_min
        pre_max[0] = nums[0];
        suf_min[n - 1] = nums[n - 1];
        for (int i = 1; i < n; ++i) {
            pre_max[i] = max(nums[i], pre_max[i - 1]);
            suf_min[n - i - 1] = min(suf_min[n - i], nums[n - i - 1]);
        }

        vector<int> result(n);

        // suppose we're checking the last number j
        // if nums[j] == pre_max[j], then it's obvious
        // if nums[j] < pre_max[j], assume pre_max[j] == nums[i], where i < j
        // then we know that i < j and nums[i] > nums[j], so we can jump from i
        // to j, so result[j] = pre_max[j]
        result[n - 1] = pre_max[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (pre_max[i] > suf_min[i + 1]) {
                result[i] = result[i + 1];
            } else {
                result[i] = pre_max[i];
            }
        }

        return result;
    }
};
// @leet end
