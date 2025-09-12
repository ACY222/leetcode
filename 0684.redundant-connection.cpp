// @leet start
#include <vector>
using std::vector;
class Solution {
  class UnionFind {
  private:
    int count;  // number of connected components
    vector<int> parent, size;
    //
  public:
    UnionFind(int n) {
      // at the beginning, no two nodes is connected, so the count is n, and
      // every nodes points to itself
      count = n;
      parent.resize(n + 1);
      size.resize(n + 1, 1);
      for (int i = 0; i <= n; ++i) {
        parent[i] = i;
      }
    }

    int find(int x) {
      // so that the depth of the tree is O(1)
      while (x != parent[x]) {
        parent[x] = parent[parent[x]];
        x = parent[x];
      }
      return x;
    }

    vector<int> unionTwoNodes(int p, int q) {
      int rootP {find(p)}, rootQ(find(q));
      if (rootP == rootQ) {   // they are in the same tree
        return {p, q};
      }
      // make small tree the child of big tree so that the depth of the tree is
      // O(log N)
      if (size[rootP] > size[rootQ]) {
        parent[rootQ] = rootP;
        size[rootP] += size[rootQ];
      }
      else {
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
      }
      --count;
      return {};
    }
  };
public:
  // use dfs to check if there is a cycle? and remove the last cycle
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> extraEdge;
    UnionFind uf(n);
    for (vector<int>& edge : edges) {
      extraEdge = uf.unionTwoNodes(edge[0], edge[1]);
      if (!extraEdge.empty()) {
        return extraEdge;
      }
    }
    return {};
  }
};
// @leet end
