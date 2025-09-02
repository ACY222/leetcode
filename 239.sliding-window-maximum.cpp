// @leet start
#include <cstdlib>
#include <deque>
#include <vector>
using std::vector;
using std::deque;
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq {};
    vector<int> res {};
    int n {(int)nums.size()};
    for (int i = 0; i < k; ++i) {
      int num {nums[i]};
      while (!dq.empty() && dq.back() < num) {
        dq.pop_back();
      }
      dq.push_back(num);
    }
    res.push_back(dq.front());
    for (int i = k; i < n; ++i) {
      int num {nums[i]};
      if (dq.front() == nums[i - k]) {
        dq.pop_front();
      }
      while (!dq.empty() && dq.back() < num) {
        dq.pop_back();
      }
      dq.push_back(num);
      res.push_back(dq.front());
    }
    return res;
  }
};
// @leet end
