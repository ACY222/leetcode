// @leet start
#include <algorithm>
#include <utility>
#include <vector>
using std::vector;
using std::sort;
using std::pair, std::make_pair;
class Solution {
private:
  vector<int> parent;
  vector<vector<int>> res = {{}, {}};

  // initialize parent to be [0:n] and sort edges
  void init(int numNodes, int numEdges, vector<vector<int>>& edges) {
    parent.reserve(numNodes);
    for (int i = 0; i < numNodes; ++i) {
      parent.push_back(i);
    }
    for (int i = 0; i < numEdges; ++i) {
      edges[i].push_back(i);  // now edge[3] is its original index
    }
    auto compare = [](vector<int>& u, vector<int>& v) { return u[2] < v[2]; };
    sort(edges.begin(), edges.end(), compare);
  }

  int find(int x) {
    while (x != parent[x]) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }

  bool connect(int p, int q) {
    int rootP = find(p), rootQ = find(q);
    if (rootP == rootQ) {
      return false;
    }
    parent[rootQ] = rootP;
    return true;
  }

  int Kruskal(int numNodes, int numEdges, vector<vector<int>>& edges) {
    int total = 0, num = 0;
    for (vector<int>& edge : edges) {
      if (connect(edge[0], edge[1])) {  // if we can connect them
        total += edge[2];
        ++num;
      }
    }
    return total;
  }

  void checkCriticalKruskal(int numNodes, int numEdges, vector<vector<int>>& edges, vector<int>& _edge, int distance) {
    // check if it's critical edge by skipping the edge, and check if the
    // distance increase
    for (int i = 0; i < numNodes; ++i) {
      parent[i] = i;
    }
    int total = 0, num = 0;
    for (vector<int>& edge : edges) {
      if (edge == _edge) {    // skip current edge
        continue;
      }
      if (connect(edge[0], edge[1])) {
        total += edge[2];
        ++num;
        if (num == numNodes - 1) {
          break;
        }
      }
    }
    if (total > distance or num < numNodes - 1) {
      res[0].push_back(_edge[3]); // so we must use this edge
      return;
    }
    // check if it's pseudo critical edge by accepting it, and see if the
    // distance is same with minDistance
    for (int i = 0; i < numNodes; ++i) {
      parent[i] = i;
    }
    connect(_edge[0], _edge[1]);  // connect this edge at first
    total = _edge[2], num = 1;
    for (auto& edge : edges) {
      if (edge == _edge) {
        continue;
      }
      if (connect(edge[0], edge[1])) {
        total += edge[2];
        ++num;
        if (num == numNodes - 1) {
          break;
        }
      }
    }
    if (total == distance) {
      res[1].push_back(_edge[3]);
      return;
    }
  }


public:
  // n is the number of nodes
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
    int m = edges.size(), minDistance;     // m is numEdges
    init(n, m, edges);
    minDistance = Kruskal(n, m, edges);
    for (vector<int>& edge : edges) {
      checkCriticalKruskal(n, m, edges, edge, minDistance);
    }
    return res;
  }
};
// @leet end
