// @leet start
#include <string>
#include <unordered_set>
#include <vector>
using std::vector, std::string;
using std::unordered_set;
class Solution {
  class UnionFind {
  private:
    int count;
    vector<int> size, parent;
    vector<unordered_set<int>> inequal;
    bool satisfy {true};
  public:
    UnionFind(int n) {
      count = n;
      size.resize(n, 1);
      parent.resize(n);
      inequal.resize(n);  // to record it's different from what
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

    void equal(char c1, char c2) {
      int p = c1 - 'a', q = c2 - 'a';
      int rootP = find(p), rootQ = find(q);
      // if they are inequal in previous equations
      if (inequal[rootP].count(rootQ) or inequal[rootQ].count(rootP)) {
        satisfy = false;
        return;
      }
      // if they are not inequal and they have been in the same set
      if (rootP == rootQ) {
        return;
      }
      // if there was no relationship between them, union them
      if (size[rootP] > size[rootQ]) {
        parent[rootQ] = rootP;
        size[rootP] += size[rootQ];
        inequal[rootP].insert(inequal[rootQ].begin(), inequal[rootQ].end());
      }
      else {
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
        inequal[rootQ].insert(inequal[rootP].begin(), inequal[rootP].end());
      }
      --count;
      return;
    }

    void notEqual(char c1, char c2) {
      int p = c1 - 'a', q = c2 - 'a';
      int rootP = find(p), rootQ = find(q);
      if (rootP == rootQ) {   // if they are in the same set
        satisfy = false;
        return;
      }
      if (inequal[rootP].count(rootQ) or inequal[rootQ].count(rootP)) {
        return;
      }
      inequal[rootP].insert(rootQ);
      inequal[rootQ].insert(rootP);
      return;
    }

    bool canSatisfy() {
      return satisfy;
    }

  };
public:
  bool equationsPossible(vector<string>& equations) {
    UnionFind uf(26);   // there are at most 26 lowercase letters
    for (string equation : equations) {
      if (!uf.canSatisfy()) {
        return false;
      }
      char c1 = equation[0], c2 = equation[3];
      if (equation[1] == '!') {
        uf.notEqual(c1, c2);
      }
      else {
        uf.equal(c1, c2);
      }
    }
    return uf.canSatisfy();
  }
};
// @leet end
