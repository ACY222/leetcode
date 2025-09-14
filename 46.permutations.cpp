// @leet start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<int>> res;

  void backtrack(vector<int>& nums, const int start) {
    if (start == nums.size()) {
      res.push_back(nums);
      return;
    }

    for (int i = start; i < nums.size(); ++i) {
      swap(nums[i], nums[start]);
      backtrack(nums, start + 1);
      swap(nums[i], nums[start]);
    }
  }

public:
  vector<vector<int>> permute(vector<int>& nums) {
    backtrack(nums, 0);
    return res;
  }
};
// @leet end
