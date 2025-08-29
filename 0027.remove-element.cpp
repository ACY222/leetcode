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
      // if we nums[fast] is not val, assign it to position slow
      if (nums[fast] != val) {
        nums[slow++] = nums[fast];
      }
      ++fast;
    }
    return slow;
  }
};
// @leet end
