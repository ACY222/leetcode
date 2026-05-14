// @leet start
#include <vector>
using namespace std;
class Solution {
public:
    bool isGood(vector<int>& nums) {
        // nums might be a permutation of base[n - 1]
        int n = nums.size();
        bool is_first = true;
        vector<bool> visited(n, false);

        for (auto num : nums) {
            if (num >= n) { return false; }
            if (visited[num - 1] == false) {
                visited[num - 1] = true;
            }
            // visited[num - 1] == true
            else if (num != n - 1) {
                return false;
            } else {
                if (is_first) {
                    is_first = false;
                } else {
                    return false;
                }
            }
        }

        if (is_first) { return false; }
        return true;
    }
};
// @leet end
