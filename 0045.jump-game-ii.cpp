// @leet start
#include <algorithm>
#include <vector>
using std::vector;
using std::max;
class Solution {
public:
  int jump(vector<int>& nums) {
    int steps {0}, maxReach {0}, currentEnd {0};
    // if i == nums.size() - 1, it means we currentEnd(last maxReach) >
    // nums.size(). So we have already arrived the end
    for (int i = 0; i < nums.size() - 1; ++i) {
      maxReach = max(maxReach, i + nums[i]);
      // currentEnd is the maxReach we can jump to in last round
      if (i == currentEnd) {
        currentEnd = maxReach;
        ++steps;
      }
    }
    return steps;
  }
};
// @leet end
