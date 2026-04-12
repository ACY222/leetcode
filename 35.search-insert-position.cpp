// @leet start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // sorted array of distinct ints
    int searchInsert(vector<int>& nums, int target) {
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        return (it - nums.begin());
        // int size = nums.size();
        // int idx = size / 2;
        // while (nums[idx] != target) {
        //     if (nums[idx] < target) {
        //         if (idx == size - 1) { return size; }
        //         idx = (idx + size) / 2;
        //     } else {
        //         if (idx == 0) { return 0; }
        //         idx = idx / 2;
        //     }
        // }
        //
        // return idx;
    }
};
// @leet end
