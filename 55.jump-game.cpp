// @leet start
#include <vector>
using std::vector;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    for (int index = 0; index < nums.size(); ) {
      // we can jump to the end directly
      if (index + nums[index] >= nums.size() - 1) {
        return true;
      }
      // try to move as far as possible
      int maxStep {index + nums[index]}, nextIndex {index};
      for (int i = 1; i <= nums[index]; ++i) {
        if (nums[index + i] + index + i > maxStep) {
          maxStep = nums[index + i] + index + i;
          nextIndex = index + i;
        }
      }
      // if we cannot move forward
      if (index >= nextIndex) {
        return false;
      }
      index = nextIndex;
    }
    return false;
  }
};
// @leet end
