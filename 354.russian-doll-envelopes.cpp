// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    // both width and height are greater->can fit into
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        // we can at least russian doll the envelope itself
        vector<int> nums(envelopes.size(), 1);
        for (int i = 1; i < envelopes.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] and
                    envelopes[i][1] > envelopes[j][1]) {
                    nums[i] = max(nums[i], nums[j] + 1);
                }
            }
        }
        return *max_element(nums.begin(), nums.end());
    }
};
// @leet end
