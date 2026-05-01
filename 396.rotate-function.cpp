// @leet start
#include <vector>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int rotate_func = INT_MIN, n = nums.size();
        int sum = 0, rotate_func_last = 0;

        for (int i = 0; i < n; ++i) {
            rotate_func_last += (i * nums[i]);
            sum += nums[i];
        }

        rotate_func = rotate_func_last;

        for (int k = 1; k < n; ++k) {
            int rotate_func_k =
                rotate_func_last + sum - n * nums[(2 * n - k) % n];

            rotate_func = max(rotate_func, rotate_func_k);
            rotate_func_last = rotate_func_k;
        }
        return rotate_func;
    }
};
// @leet end
