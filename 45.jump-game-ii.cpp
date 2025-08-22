// @leet start
#include <vector>
using std::vector;
class Solution {
public:
  int jump(vector<int>& nums) {
    if (nums.size() == 1) {
      return 0;
    }
    return jumpFromGivenPosition(nums, 0);
  }
private:
  int jumpFromGivenPosition(vector<int>& nums, int index) {
    if (index + nums[index] >= nums.size() - 1) {
      return 1;
    }
    int maxStep {index + nums[index]}, nextIndex {index};
    for (int i = 1; i <= nums[index]; ++i) {
      if (index + i + nums[index + i] > maxStep) {
        maxStep = index + i + nums[index + i];
        nextIndex = index + i;
      }
    }
    return 1 + jumpFromGivenPosition(nums, nextIndex);
  }
};
// @leet end
