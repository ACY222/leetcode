#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, suffix = 1, n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; ++i) {
            prefix *= nums[i - 1];
            suffix *= nums[n - i];
            res[i] *= prefix;
            res[n - i - 1] *= suffix;
        }
        return res;
    }
};