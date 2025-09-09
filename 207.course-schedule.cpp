// @leet start
#include <vector>
using std::vector;
class Solution {
private:
  vector<vector<int>> convertToGraph(int num, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(num, vector<int>());
    for (auto& edge : prerequisites) {
      int from = edge[1], to = edge[0];
      graph[from].push_back(to);
    }
    return graph;
  }

  void traverse(int currNum, vector<vector<int>>& graph, bool& hasCycle, vector<bool>& onPath, vector<bool>& visited) {
    if (hasCycle) {
      return;
    }

    if (onPath[currNum]) {
      hasCycle = true;
      return;
    }

    if (visited[currNum]) {
      return;
    }

    visited[currNum] = true;
    onPath[currNum] = true;
    for (int child : graph[currNum]) {
      traverse(child, graph, hasCycle, onPath, visited);
    }

    onPath[currNum] = false;
  }

public:
  // prerequisites[i] = {ai, bi}. and bi is prerequisite of ai
  // topo sort?
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if (prerequisites.size() == 0) {
      return true;
    }
    // convert the prerequisites to a graph represented by adjencency list
    vector<vector<int>> graph = convertToGraph(numCourses, prerequisites);
    vector<bool> onPath(numCourses, false), visited(numCourses, false);
    bool hasCycle {false};
    for (int i = 0; i < numCourses; ++i) {
      traverse(i, graph, hasCycle, onPath, visited);
    }

    return !hasCycle;
  }
};
// @leet end
