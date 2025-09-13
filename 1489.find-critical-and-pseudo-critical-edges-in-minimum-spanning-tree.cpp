// @leet start
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;
class Solution {
private:
  vector<int> parent;
  vector<vector<int>> criticalAndPseudo;

  static constexpr int P = 0;
  static constexpr int Q = 1;
  static constexpr int W = 2;
  static constexpr int IDX = 3;

  void resetUnionFind() {
    iota(parent.begin(), parent.end(), 0);
  }

  // initialize parent, sizes and sort edges by non-decending weight
  void init(vector<vector<int>>& edges, int n) {
    parent.resize(n);
    resetUnionFind();
    for (int i = 0; i < edges.size(); ++i) {
      edges[i].push_back(i);    // record the original indices for all edges
    }
    auto compare = [](vector<int>& a , vector<int>& b) { return a[W] < b[W]; };
    sort(edges.begin(), edges.end(), compare);
    return;
  }

  int find(int x) {
    while (parent[x] != x) {
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
    return true;
  }

  int Kruskal(vector<vector<int>>& edges, int n) {
    int num = 0, total = 0; // num is the number of connected edges
    for (auto& e : edges) {
      if (unite(e[P], e[Q])) {
        total += e[W];
        if (++num == n - 1) {
          return total;
        }
      }
    }
    return -1;
  }

  bool isCritical(vector<vector<int>>& edges, vector<int>& edge, int n, int minTotal) {
    resetUnionFind();
    // skip the edge and check if the total increase or if we can connect all
    // the vertices
    int connected = 0, total = 0;
    for (auto& e : edges) {
      if (e[IDX] == edge[IDX]) {
        continue;
      }
      if (unite(e[P], e[Q])) {
        total += e[W];
        ++connected;
      }
    }
    return (total > minTotal) or (connected != n - 1);
  }

  bool isPseudoCritical(vector<vector<int>>& edges, vector<int>& edge, int n, int minTotal) {
    resetUnionFind();
    // if the edge is not critical
    // accept the edge and check if the total stay the same
    unite(edge[P], edge[Q]);
    int connected = 1, total = edge[W];
    for (auto& e : edges) {
      if (e[IDX] == edge[IDX]) {
        continue;
      }
      if (unite(e[P], e[Q])) {
        total += e[W];
        if (++connected == n - 1) break;
      }
    }
    return total == minTotal;
  }

public:
  Solution() : criticalAndPseudo(2) {}
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
    init(edges, n);
    int total = Kruskal(edges, n);
    for (auto& edge : edges) {
      if (isCritical(edges, edge, n, total)) {
        criticalAndPseudo[0].push_back(edge[IDX]);
      }
      else if (isPseudoCritical(edges, edge, n, total)) {
        criticalAndPseudo[1].push_back(edge[IDX]);
      }
    }
    return criticalAndPseudo;
  }
};
// @leet end
