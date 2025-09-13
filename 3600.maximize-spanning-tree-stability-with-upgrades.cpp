// @leet start
#include <algorithm>
#include <climits>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> parent, sizes;

  static constexpr int P = 0;
  static constexpr int Q = 1;
  static constexpr int W = 2;
  static constexpr int MUST = 3;

  void init(int n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    sizes.resize(n, 1);
  }

  int find(int x) {
    while (x != parent[x]) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }

  bool unite(int p, int q) {
    p = find(p), q = find(q);
    if (p == q) {
      return false;
    }
    parent[q] = p;
    sizes[p] += sizes[q];
    return true;
  }

  bool isMST(int n) {
    return sizes[find(0)] == n;
  }

  bool connectCompulsory(vector<vector<int>>& edges, priority_queue<vector<int>>& pq, int& res) {
    for (auto& e : edges) {
      // if it's must
      if (e[MUST]) {
        // if there is redundant compulsory edges, we cannot generate a MST
        if (!unite(e[P], e[Q])) {
          return false;
        }
        // otherwise, update res
        res = min(res, e[W]);
      }
      else {
        pq.push({e[W], e[P], e[Q]});
      }
    }
    return true;
  }

  bool connectOptional(priority_queue<vector<int>>& pq, stack<int>& st, int n) {
    while (!pq.empty()) {
      int p = pq.top()[1], q = pq.top()[2], str = pq.top()[0];
      pq.pop();
      // note that the order of the elements changed, so we cannot use P, Q, W
      if (unite(p, q)) {
        st.push(str);
      }
    }
    return isMST(n);
  }

public:
  int maxStability(int n, vector<vector<int>>& edges, int k) {
    priority_queue<vector<int>> pq;
    stack<int> st;
    int res = INT_MAX;
    init(n);
    if (!connectCompulsory(edges, pq, res)) {
      return -1;
    }
    // now all the non-must edges are in the priority_queue
    if (!connectOptional(pq, st, n)) {
      return -1;
    }
    while (!st.empty() and k > -1) {
      res = min(res, (st.top() << (k > 0)));
      st.pop();
      --k;
    }
    return res;
  }
};
// @leet end
