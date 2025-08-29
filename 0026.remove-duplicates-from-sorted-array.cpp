// @leet start
#include <vector>

using std::vector;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int slow {0}, fast {0};
    while (fast < nums.size()) {
      // if we find a new number, move slow forward and copy the value
      if (nums[fast] != nums[slow]) {
        nums[++slow] = nums[fast];
      }
      ++fast;
    }
    return slow + 1;
  }
};
// @leet end
