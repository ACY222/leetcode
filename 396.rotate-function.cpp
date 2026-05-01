// @leet start
#include <vector>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int rotate_func = INT_MIN, n = nums.size();

        for (int k = 0; k < n; ++k) {
            int rotate_func_k = 0;
            for (int i = 0; i < n; ++i) {
                rotate_func_k += i * nums[(i - k + n) % n];
            }

            rotate_func = max(rotate_func, rotate_func_k);
        }
        return rotate_func;
    }
};
// @leet end
