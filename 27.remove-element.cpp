// @leet start
#include <vector>

using std::vector;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) {
      return 0;
    }
    int slow {0}, fast {(int)nums.size() - 1};
    while (fast > slow) {
      // if we find a val in nums, we need to find another element to replace
      if (nums[slow] == val) {
        // so we keep moving fast backward to find an element
        while (fast > slow && nums[fast] == val) {
          --fast;
        }
        // if fast > slow, it means we find that, assign it to nums[slow]
        if (fast > slow) {
          nums[slow] = nums[fast];
          --fast;
          continue;
        }
        // otherwise, fast <= slow
        break;
      }
      // keep moving slow forward
      ++slow;
    }
    return nums[slow] == val ? slow : slow + 1;
  }
};
// @leet end
