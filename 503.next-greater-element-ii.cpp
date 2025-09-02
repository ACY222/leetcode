// @leet start
#include <algorithm>
#include <stack>
#include <vector>
using std::vector;
using std::stack;
using std::max_element;
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n {(int)nums.size()}, count {0}, maxVal {*max_element(nums.begin(), nums.end())}, maxValNum {0};
    for (int num : nums) {
      if (num == maxVal) {
        ++maxValNum;
      }
    }
    stack<int> st;
    vector<int> res(n, -1);
    vector<bool> visited(n, false);
    for (int i = n - 1; ; i = (i + n - 1) % n) {
      if (visited[i]) {
        continue;
      }
      while (!st.empty() and st.top() <= nums[i]) {
        st.pop();
      }
      if (!st.empty()) {
        res[i] = st.top();
        visited[i] = true;
        ++count;
      }
      st.push(nums[i]);
      if (count == n - maxValNum) {
        return res;
      }
    }
    return {};
  }
};
// @leet end
