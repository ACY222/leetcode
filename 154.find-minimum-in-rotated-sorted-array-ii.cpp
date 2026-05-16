// @leet start
#include <vector>
using namespace std;
class Solution {
public:
    // 10 1 10 10 10
    //  l    m     r
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1; // left and right
        while (left < right) {
            int mid = (left + right) / 2;

            // smaller than previous one, then nums[mid + 1] = nums_min
            if (nums[mid] > nums[mid + 1]) { return nums[mid + 1]; }

            if (nums[left] < nums[mid]) {
                // left < mid, mid > right (left half)
                if (nums[mid] > nums[right]) {
                    left = mid;
                } else { // left < mid <= right
                    return nums[left];
                }
            } else if (nums[left] == nums[mid]) {
                // left == mid, mid + 1 == right
                // nums[mid] <= nums[right]
                if (left == mid) {
                    return nums[left];
                } else {
                    // 10 1 10 10 10
                    // 10 10 10 1 10
                    for (int i = left; i < mid; ++i) {
                        if (nums[i] > nums[i + 1]) { return nums[i + 1]; }
                    }
                    left = mid;
                }
            }
            // left > mid, mid < right (right half)
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};
// @leet end
