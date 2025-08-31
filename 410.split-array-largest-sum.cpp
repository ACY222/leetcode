// @leet start
#include <algorithm>
#include <vector>
using std::vector;
using std::max_element;
class Solution {
public:
  int splitArray(vector<int>& nums, int k) {
    // left = nums.max_element(), right = nums.sum_element()
    int left {0}, right {0}, mid;
    for (int num : nums) {
      left = num > left ? num : left;
      right += num;
    }
    while (left < right) {
      mid = left + (right - left) / 2;
      if (sumLessThanMid(nums, k, mid)) {
        right = mid;
      }
      else {
        left = mid + 1;
      }
    }
    return left;
  }
private:
  bool sumLessThanMid(vector<int>& nums, int k, int mid) {
    int numOfArray {0}, n {(int)nums.size()}, remainSum {mid};
    for (int i = 0; i < n; ++i) {
      if (nums[i] > remainSum) {
        remainSum = mid;
        ++numOfArray;
      }
      remainSum -= nums[i];
    }
    return numOfArray < k;
  }
};
// @leet end
