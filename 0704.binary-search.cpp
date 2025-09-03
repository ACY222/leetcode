// @leet start
#include <vector>
using std::vector;
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int n {(int)nums.size()}, left {0}, right {n}, middle {(left + right) / 2};
    while (nums[middle] != target) {
      if (nums[middle] < target) {
        left = middle + 1;
      }
      else {
        right = middle;
      }
      if (left >= right) {
        return -1;
      }
      middle = (left + right) / 2;
    }
    return middle;
  }
};
// @leet end
