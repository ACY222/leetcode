// @leet start
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
  vector<int> parent, size;

  static constexpr int U = 0;
  static constexpr int V = 1;
  static constexpr int STR = 2;
  static constexpr int MUST = 3;

  void resetUnionFind() {
    iota(parent.begin(), parent.end(), 0);
  }

  void init(int n, vector<vector<int>>& edges) {
    // initialize parent and size
    parent.resize(n);
    resetUnionFind();
    size.resize(n, 1);

    // sort edges by musti and strength
    auto compare = [](vector<int>& a, vector<int>& b) {
      if (a[MUST] != b[MUST]) {
        return a[MUST] > b[MUST];
      }
      else {
        return a[STR] > b[STR];
      }
    };
    sort(edges.begin(), edges.end(), compare);
  }

  int find(int x) {
    while (x != parent[x]) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }

  bool unite(int p, int q) {
    int rootP = find(p), rootQ = find(q);
    if (rootP == rootQ) {
      return false;
    }
    parent[rootQ] = rootP;
    size[rootP] += size[rootQ];
    return true;
  }

public:
  // 0. Sort the edges, first by descending musti, second by descending strength
  // 1. unite all the edges with musti == 1(and check if there's redundant edge)
  // 2. unite the edges with musti == 0
  int maxStability(int n, vector<vector<int>>& edges, int k) {
    int m = edges.size(), numConnectedEdges = 0, i = 0, numOptional = 0;
    bool hasMust = false;
    vector<int> minStabs {};
    init(n, edges);
    // the first several edges are compulsory
    while (i < m and edges[i][MUST] == 1) {
      auto& edge = edges[i++];
      if (!unite(edge[U], edge[V])) {
        return -1;
      }
    }
    if (i != 0) {
      minStabs.push_back(edges[i - 1][STR]);
      hasMust = true;
    }
    numConnectedEdges = i;
    while (i < m) { // now edges[i][MUST] == 0
      auto& edge = edges[i++];
      if (unite(edge[U], edge[V])) {
        minStabs.push_back(edge[STR]);
        ++numOptional;
        if (++numConnectedEdges == n - 1) {
          if (k == 0) {
              return min(minStabs[0], minStabs[numOptional]);
          }
          else {
            if (numOptional <= k) {
              if (hasMust) {
                return min(minStabs[0], minStabs[numOptional] * 2);
              }
              else {
                return minStabs[numOptional] * 2;
              }
            }
            else {
              return min(min(minStabs[0], minStabs[numOptional - k]), minStabs[numOptional] * 2);
            }
          }
        }
      }
    }
    return -1;
  }
};
// @leet end
