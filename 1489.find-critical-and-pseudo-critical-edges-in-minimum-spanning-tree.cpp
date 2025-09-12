// @leet start
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
private:
  vector<int> ufParent;
  vector<vector<int>> criticalAndPseudo;

  static constexpr int U = 0;
  static constexpr int V = 1;
  static constexpr int W = 2;
  static constexpr int IDX = 3;


  void resetUnionFind() {
    iota(ufParent.begin(), ufParent.end(), 0);
  }

  // initialize parent to be [0:n] and sort edges
  void init(int n, vector<vector<int>>& edges) {
    ufParent.resize(n);
    resetUnionFind();
    for (int i = 0; i < edges.size(); ++i) {
      edges[i].push_back(i);  // now edge[IDX] is its original index
    }
    auto compare = [](vector<int>& a, vector<int>& b) { return a[W] < b[W]; };
    sort(edges.begin(), edges.end(), compare);
  }

  int find(int x) {
    while (x != ufParent[x]) {
      ufParent[x] = ufParent[ufParent[x]];
      x = ufParent[x];
    }
    return x;
  }

  bool unite(int p, int q) {
    int rootP = find(p), rootQ = find(q);
    if (rootP == rootQ) {
      return false;
    }
    ufParent[rootQ] = rootP;
    return true;
  }

  int Kruskal(int n, vector<vector<int>>& edges) {
    int total = 0, num = 0;
    for (auto& edge : edges) {
      if (unite(edge[U], edge[V])) {  // if we can unite them
        total += edge[W];
        if (++num == n - 1) break;
      }
    }
    return total;
  }

  bool isCritical(int n, vector<vector<int>>& edges, vector<int>& targetEdge, int minTotal) {
    resetUnionFind();
    int total = 0, connected = 0;
    for (auto& edge : edges) {
      if (edge[IDX] == targetEdge[IDX]) {
        continue;
      }
      if (unite(edge[U], edge[V])) {
        total += edge[W];
        if (++connected == n - 1) break;
      }
    }
    return (total > minTotal) or (connected < n - 1);
  }

  bool isPseudoCritical(int n, vector<vector<int>>& edges, vector<int>& targetEdge, int minTotal) {
    resetUnionFind()  ;
    unite(targetEdge[U], targetEdge[V]);
    int total = targetEdge[W], connected = 1;
    for (auto& edge : edges) {
      if (edge[IDX] == targetEdge[IDX]) {
        continue;
      }
      if (unite(edge[U], edge[V])) {
        total += edge[W];
        if (++connected == n - 1) break;
      }
    }
    return total == minTotal;
  }

public:
  // use constructor!
  Solution() : criticalAndPseudo(2) {}
  // n is the number of nodes
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
    init(n, edges);

    int minTotal = Kruskal(n, edges);
    for (auto& edge : edges) {
      if (isCritical(n, edges, edge, minTotal)) {
        criticalAndPseudo[0].push_back(edge[IDX]);
      }
      else if (isPseudoCritical(n, edges, edge, minTotal)) {
        criticalAndPseudo[1].push_back(edge[IDX]);
      }
    }
    return criticalAndPseudo;
  }
};
// @leet end
