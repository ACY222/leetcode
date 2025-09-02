// @leet start
#include <cstdlib>
#include <deque>
#include <vector>
using std::vector;
using std::deque;
class Solution {
public:
  class MonotonicQueue {
  public:
    void push(int n) {
      // remove the smaller numbers before n
      while (!data.empty() && data.back() < n) {
        data.pop_back();
      }
      data.push_back(n);
    }

    // we have poped the extra smaller numbers, so we need to check if we should
    // pop
    void pop(int n) {
      if (data.front() == n) {
        data.pop_front();
      }
    }

    int max() {
      // for we pop all the number less than n when push(n), the number at the
      // front must the max
      return data.front();
    }
  private:
    deque<int> data;
  };
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue mq {};
    vector<int> res {};
    int n {(int)nums.size()};
    for (int i = 0; i < k; ++i) {
      mq.push(nums[i]);
    }
    res.push_back(mq.max());
    for (int i = k; i < n; ++i) {
      mq.pop(nums[i - k]);
      mq.push(nums[i]);
      res.push_back(mq.max());
    }
    return res;
  }
};
// @leet end
