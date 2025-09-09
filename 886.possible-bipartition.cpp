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

  vector<vector<int>> convertToGraph(vector<vector<int>>& edges, int n) {
    vector<vector<int>> graph(n, vector<int>());
    for (vector<int>& edge : edges) {
      // for dislikes is 1-based and graph is 0-based
      int u = edge[0] - 1, v = edge[1] - 1;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    return graph;
  }

public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    visited.resize(n + 1);   colors.resize(n + 1);
    vector<vector<int>> graph = convertToGraph(dislikes, n);
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        traverse(graph, i);
      }
    }
    return res;
  }
};
// @leet end
