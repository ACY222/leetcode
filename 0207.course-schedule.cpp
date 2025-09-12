// @leet start
#include <vector>
using std::vector;
class Solution {
private:
  vector<bool> visited, onPath;
  bool hasCycle {false};

  vector<vector<int>> generateGraph(vector<vector<int>>& edges, int num) {
    vector<vector<int>> graph(num, vector<int>());
    for (vector<int> edge : edges) {
      int to = edge[0], from = edge[1];
      graph[from].push_back(to);
    }
    return graph;
  }

  void traverse(vector<vector<int>>& graph, int s) {
    if (hasCycle) {
      return;
    }
    if (onPath[s]) {
      hasCycle = true;
      return;
    }
    if (visited[s]) {
      return;
    }

    onPath[s] = true;
    visited[s] = true;
    for (int child : graph[s]) {
      traverse(graph, child);
    }
    onPath[s] = false;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if (prerequisites.size() == 0) {
      return true;
    }
    visited.resize(numCourses); onPath.resize(numCourses);
    vector<vector<int>> graph = generateGraph(prerequisites, numCourses);
    for (int i = 0; i < numCourses; ++i) {
      traverse(graph, i);
    }
    return !hasCycle;
  }
};
// @leet end
