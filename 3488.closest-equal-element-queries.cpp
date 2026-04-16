// @leet start
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> ans(n, n + 1);
        vector<int> last_pos(1000001, -1);

        for (int i = 0; i < 2 * n; ++i) {
            int val = nums[i % n];
            // val has been existed
            if (last_pos[val] != -1) {
                int dist = i - last_pos[val];
                ans[i % n] = min(ans[i % n], dist);
                ans[last_pos[val] % n] = min(ans[last_pos[val] % n], dist);
            }

            // update last position
            last_pos[val] = i;
        }

        vector<int> res;
        res.reserve(queries.size());
        for (int idx : queries) {
            if (ans[idx] >= n) {
                res.push_back(-1);
            } else {
                res.push_back(ans[idx]);
            }
        }

        return res;
    }
};
// @leet end
