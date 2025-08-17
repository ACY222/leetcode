// @leet start
#include <vector>

using std::vector;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) {
      return 0;
    }
    int slow {0}, fast {0};
    while (fast < nums.size()) {
      // if we find a val in nums, we need to find another element to replace
      if (nums[fast] != val) {
        nums[slow++] = nums[fast];
      }
      ++fast;
    }
    return slow;
  }
};
// @leet end
