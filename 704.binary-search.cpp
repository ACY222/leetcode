// @leet start
#include <vector>
using std::vector;
class Solution {
public:
  int search(vector<int>& nums, int target) {
    return searchWithBoundary(nums, 0, nums.size(), target);
  }
private:
  int searchWithBoundary(vector<int>& nums, int left, int right, int target) {
    if (right <= left) {            // if the vector is "empty"
      return -1;
    }
    else if (right == left + 1) {   // if there's only one number in the vector
      if (nums[left] == target) {
        return left;
      }
      return -1;
    }
    int middle {(left + right) / 2};
    if (nums[middle] == target) {
      return middle;
    }
    else if (nums[middle] < target) {
      return searchWithBoundary(nums, middle, right, target);
    }
    else {
      return searchWithBoundary(nums, left, middle, target);
    }
  }
};
// @leet end
