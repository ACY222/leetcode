// @leet start
#include <vector>
using std::vector;
class NumArray {
public:
  NumArray(vector<int>& nums) {
    this->nums = nums;
    for (int i = 0, sum = 0; i < nums.size(); ++i) {
      sum += nums[i];
      this->prefixSum.push_back(sum);
    }
  }

  int sumRange(int left, int right) {
    if (left == 0) {
      return this->prefixSum[right];
    }
    return this->prefixSum[right] - this->prefixSum[left - 1];
  }
private:
  vector<int> nums;
  vector<int> prefixSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @leet end
