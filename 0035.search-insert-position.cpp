// @leet start
#include <vector>
using namespace std;

class Solution {
public:
    // sorted array of distinct ints
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int left {0}, right {size - 1};
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                // left == mid == right, nums[mid] > target
                if (right == mid) { return mid; }
                right = mid;
            }
        }

        return left;
    }
};
// @leet end
