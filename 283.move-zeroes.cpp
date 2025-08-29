// @leet start
#include <vector>
using std::vector;
class Solution {
public:
  // we must do it in-place and maintain the relative order
  void moveZeroes(vector<int>& nums) {
    // fast looks for non-zero element, slow looks for 0 element
    int slow {0}, fast {0};
    while (slow < nums.size() && fast < nums.size()) {
      while (slow < nums.size() && nums[slow]) {
        ++slow;
      }
      while (fast < slow || (fast < nums.size() && !nums[fast])) {
        ++fast;
      }
      if (fast == nums.size() || slow == nums.size()) {
        return;
      }
      nums[slow] = nums[fast];
      nums[fast] = 0;
    }
    return;
  }
};
// @leet end
