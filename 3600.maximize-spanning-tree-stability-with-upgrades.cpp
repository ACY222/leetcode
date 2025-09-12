// @leet start
#include <climits>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
private:
  vector<int> parent, sizes;
public:
  UnionFind(int n) {
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

  int getTreeSize() {
    return sizes[find(0)];
  }

};

class Solution {
private:
  int minStr = INT_MAX;
  static constexpr int U = 0;
  static constexpr int V = 1;
  static constexpr int STR = 2;
  static constexpr int MUST = 3;

  bool connectCompulsoryEdges(vector<vector<int>>& edges, priority_queue<vector<int>>& pq, UnionFind& uf) {
    for (auto& e : edges) {
      if (e[MUST]) {
        minStr = min(minStr, e[STR]);
        if (!uf.unite(e[U], e[V])) {
          return false;
        }
      }
      else {
        pq.push({e[STR], e[U], e[V]});
      }
    }
    return true;
  }

  stack<int> connectOptionalEdges(priority_queue<vector<int>>& pq, UnionFind& uf) {
    stack<int> st;
    while (!pq.empty()) {
      int str = pq.top()[0], p = pq.top()[1], q = pq.top()[2];
      pq.pop();
      if (uf.unite(p, q)) {
        st.push(str);
      }
    }
    return st;
  }

public:
  int maxStability(int n, vector<vector<int>>& edges, int k) {
    priority_queue<vector<int>> pq;
    UnionFind uf(n);
    if (!connectCompulsoryEdges(edges, pq, uf)) {
      return -1;
    }
    stack<int> st = connectOptionalEdges(pq, uf);
    if (uf.getTreeSize() != n) {
      return -1;
    }
    while (!st.empty()) {
      minStr = min(minStr, (st.top() << (k > 0)));
      st.pop();
      --k;
    }
    return minStr;
  }
};
// @leet end
