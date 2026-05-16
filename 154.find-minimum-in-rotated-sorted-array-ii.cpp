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
            // this guarantees that mid != right
            int mid = (left + right) / 2;

            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else { // nums[mid] == nums[right]
                // 10 10 10 1 10
                // 10 1 10 10 10
                --right;
            }
        }

        return nums[left];
    }
};
// @leet end
