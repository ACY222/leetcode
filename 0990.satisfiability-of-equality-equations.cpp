// @leet start
#include <string>
#include <vector>
using std::vector, std::string;
class Solution {
  class UnionFind {
  private:
    vector<int> size, parent;
  public:
    UnionFind(int n) {
      size.resize(n, 1);
      parent.resize(n);
      for (int i = 0; i < n; ++i) {
        parent[i] = i;
      }
    }

    int find(int x) {
      while (x != parent[x]) {
        parent[x] = parent[parent[x]];
        x = parent[x];
      }
      return x;
    }

    void unionPQ(int p, int q) {
      int rootP = find(p), rootQ = find(q);
      // if they are not inequal and they have been in the same set
      if (rootP == rootQ) {
        return;
      }
      // if there was no relationship between them, union them
      if (size[rootP] > size[rootQ]) {
        parent[rootQ] = rootP;
        size[rootP] += size[rootQ];
      }
      else {
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
      }
      return;
    }
  };
public:
  bool equationsPossible(vector<string>& equations) {
    UnionFind uf(26);   // there are at most 26 lowercase letters
    // treat the equations first
    for (string eq : equations) {
      if (eq[1] == '=') {
        int p = eq[0] - 'a', q = eq[3] - 'a';
        uf.unionPQ(p, q);
      }
    }
    // treat the inequations now
    for (string ineq : equations) {
      if (ineq[1] == '!') {
        int p = ineq[0] - 'a', q = ineq[3] - 'a';
        if (uf.find(p) == uf.find(q)) {
          return false;
        }
      }
    }
    return true;
  }
};
// @leet end
