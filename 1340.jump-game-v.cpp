// @leet start
#include <algorithm>
#include <stack>
#include <vector>
using std::vector;
using std::max;
using std::stack;
class Solution {
public:
  // Try to use monotone stack to solve this problem
  int maxJumps(vector<int>& arr, int d) {
    int n {(int)arr.size()};
    vector<vector<int>> jumpsTo(n);
    vector<int> jumps(n, 0);
    stack<int> st {};
    // try to jump backwards
    int j;
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && arr[st.top()] < arr[i]) {
        // arr[j] < arr[i] and their distance <= d, so i can jump to j
        if (i - st.top() <= d) {
          jumpsTo[i].push_back(st.top());
        }
        st.pop();
      }
      st.push(i);
    }
    while (!st.empty()) {
      st.pop();         // clear the stack
    }
    // try to jump forwards
    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() && arr[st.top()] < arr[i]) {
        if (st.top() - i <= d) {
          jumpsTo[i].push_back(st.top());
        }
        st.pop();
      }
      st.push(i);
    }
    // find the longest length
    int maxLength {0};
    for (int i = 0; i < n; ++i) {
      if (jumps[i]) {   // if jumps[i] has been calculated before, i had been
        // jumped to. Therefore, i won't be the start of the longest path
        continue;
      }
      maxLength = max(maxLength, findLongestPath(jumpsTo, jumps, i));
    }
    return maxLength;
  }
private:
  int findLongestPath(vector<vector<int>> &jumpsTo, vector<int> &jumps, int index) {
    jumps[index] = 1;
    for (int dest : jumpsTo[index]) {
      if (jumps[dest]) {
        jumps[index] = max(jumps[index], jumps[dest] + 1);
      }
      else {
        jumps[index] = max(jumps[index], 1 + findLongestPath(jumpsTo, jumps, dest));
      }
    }
    return jumps[index];
  }
};
// @leet end
