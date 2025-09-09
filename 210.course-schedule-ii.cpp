// @leet start
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
private:
  bool hasCycle {false};
  vector<bool> visited, onPath;
  vector<int> postorder {};

  vector<vector<int>> convertToGraph(int num, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(num, vector<int>());
    for (auto& edge : prerequisites) {
      int from = edge[1], to = edge[0];
      graph[from].push_back(to);
    }
    return graph;
  }

  void traverse(int currNum, vector<vector<int>>& graph) {
    if (hasCycle) {
      return;
    }
    if (onPath[currNum]) {  // revisit a node twice
      hasCycle = true;
      return;
    }
    if (visited[currNum]) {
      return;
    }

    visited[currNum] = true;
    onPath[currNum] = true;
    for (int child : graph[currNum]) {
      traverse(child, graph);
    }

    postorder.push_back(currNum);
    onPath[currNum] = false;
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph = convertToGraph(numCourses, prerequisites);
    onPath.resize(numCourses);
    visited.resize(numCourses);
    for (int i = 0; i < numCourses; ++i) {
      traverse(i, graph);
      if (hasCycle) {
        return {};
      }
    }
    std::reverse(postorder.begin(), postorder.end());
    return postorder;
  }
};
// @leet end
