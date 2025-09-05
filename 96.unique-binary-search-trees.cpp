// @leet start
#include <vector>
using std::vector;
class Solution {
public:
  int numTrees(int n) {
    if (nums.size() != n + 1) {
      nums.resize(n + 1);
    }
    if (nums[n]) {
      return nums[n];
    }
    int sum {0};
    for (int i = 1; i <= n; ++i) {
      if (nums[i - 1] == 0) {
        nums[i - 1] = numTrees(i - 1);
      }
      if (nums[n - i] == 0) {
        nums[n - i] = numTrees(n - i);
      }
      sum += nums[i - 1] * nums[n - i];
    }
    return sum;
  }
private:
  vector<int> nums {1, 1, 2};
};
// @leet end
