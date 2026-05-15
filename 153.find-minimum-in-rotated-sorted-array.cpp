// @leet start
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1; // left and right
        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] > nums[mid + 1]) { return nums[mid + 1]; }

            if (nums[left] < nums[mid]) {
                // left < mid, mid > right (left half)
                if (nums[mid] > nums[right]) {
                    left = mid;
                } else { // left < mid < right
                    return nums[left];
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
