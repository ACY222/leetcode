// @leet start
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
using std::vector;
using std::stack, std::pair;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n {(int)temperatures.size()};
    vector<int> res(n, 0);
    stack<pair<int, int>> indexAndValue {};
    for (int i = n - 1; i >= 0; --i) {
      while (!indexAndValue.empty() and indexAndValue.top().second <= temperatures[i]) {
        indexAndValue.pop();
      }
      res[i] = indexAndValue.empty() ? 0 : indexAndValue.top().first - i;
      indexAndValue.push({i, temperatures[i]});
    }
    return res;
  }
};
// @leet end
