// @leet start
#include <vector>
using std::vector;
class Solution {
private:
  vector<bool> visited, colors; // use true and false to represent two colors
  bool res {true};
  void traverse(vector<vector<int>>& graph, int parent) {
    if (!res) {
      return;
    }
    visited[parent] = true;
    for (int child : graph[parent]) {
      if (!visited[child]) {
        colors[child] = !colors[parent];
        traverse(graph, child);
      }
      else {    // we have visited this child, check if it has different color
        if (colors[child] == colors[parent]) {
          res = false;
        }
      }
    }
  }
public:
  // this problem is the same as two-color problem
  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    visited.resize(n);
    colors.resize(n);
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        traverse(graph, i);
      }
    }
    return res;
  }
};
// @leet end
