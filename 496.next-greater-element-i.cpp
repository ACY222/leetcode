// @leet start
#include <stack>
#include <unordered_map>
#include <vector>
using std::vector;
using std::stack;
using std::unordered_map;
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int m {(int)nums1.size()}, n {(int)nums2.size()};
    unordered_map<int, int> valueToIndex {};
    vector<int> nextGreaterElement(n), res(m);
    stack<int> st {};
    for (int i = n - 1; i >= 0; --i) {
      int val {nums2[i]};
      valueToIndex[val] = i;
      while (!st.empty() and st.top() < val) {
        st.pop();
      }
      nextGreaterElement[i] = st.empty() ? -1 : st.top();
      st.push(val);
    }
    for (int i = 0; i < m; ++i) {
      res[i] = nextGreaterElement[valueToIndex[nums1[i]]];
    }
    return res;
  }
};
// @leet end
