// @leet start
#include <algorithm>
#include <queue>
#include <vector>
using std::vector;
using std::queue;

class Solution {
private:
  // generate a graph from prerequisites and calculate the indegrees
  vector<vector<int>> convertToGraph(int num, vector<vector<int>>& prerequisites, vector<int>& indegrees) {
    vector<vector<int>> graph(num, vector<int>());
    for (auto& edge : prerequisites) {
      int from = edge[1], to = edge[0];
      graph[from].push_back(to);
      ++indegrees[to];
    }
    return graph;
  }

  vector<int> BFS(vector<vector<int>>& graph, vector<int>& indegrees, int num) {
    queue<int> q;
    vector<int> res;
    for (int i = 0; i < num; ++i) {
      if (indegrees[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int parent = q.front(); q.pop();
      res.push_back(parent);
      for (int child : graph[parent]) {
        --indegrees[child];
        if (indegrees[child] == 0) {
          q.push(child);
        }
      }
    }

    if (res.size() == num) {
      return res;
    }
    return {};
  }

public:
  // use bfs
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegrees(numCourses);
    vector<vector<int>> graph = convertToGraph(numCourses, prerequisites, indegrees);
    return BFS(graph, indegrees, numCourses);
  }
};
// @leet end
