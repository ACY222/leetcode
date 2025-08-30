// @leet start
#include <vector>
using std::vector;
class Solution {
public:
  // First, find one target
  // Second, divide the vector into two parts, and then look for the boundaries
  vector<int> searchRange(vector<int>& nums, int target) {
    if (!nums.size()) {
      return {-1, -1};
    }
    int n {(int)nums.size()}, left {0}, right {n}, middle {(left + right) / 2};
    while (nums[middle] != target) {
      if (nums[middle] < target) {
        left = middle + 1;
      }
      else {
        right = middle;
      }
      if (left >= right) {
        return {-1, -1};
      }
      middle = (left + right) / 2;
    }
    // now nums[middle] == target, and there's no target outside [left, right)
    // [left, start, middle, end, right)
    int start {(left + middle) / 2}, end {(right + middle) / 2};
    if (nums[0] == target) {
      start = 0;
    }
    else {
      while (!(start != 0 && nums[start] == target && nums[start - 1] != target)) {
        if (nums[start] != target) {    // we need move start forward
          left = start + 1;
        }
        else {        // move start backward
          middle = start;
        }
        start = (left + middle) / 2;
      }
    }
    if (nums[n - 1] == target) {
      end = n - 1;
    }
    else {
      while (!(end != n - 1 && nums[end] == target && nums[end + 1] != target)) {
        if (nums[end] != target) {    // we need move start backward
          right = end;
        }
        else {        // move end forward
          middle = end + 1;
        }
        end = (right + middle) / 2;
      }
    }
    return {start, end};
  }
};
// @leet end
