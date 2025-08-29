// @leet start
#include <algorithm>
#include <vector>
using std::vector;
using std::max;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int maxReach {0};
    for (int i = 0; i < nums.size(); ++i) {
      // if we cannot reach i-th element
      if (i > maxReach) { return false; };
      maxReach = max(maxReach, i + nums[i]);
    }
    return true;
  }
};
// @leet end
