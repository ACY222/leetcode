// @leet start
#include <queue>
#include <vector>
using std::queue;
using std::vector;
class Solution {
private:
  vector<vector<int>> convertToGraph(vector<vector<int>>& prerequisites, int num, vector<int>& indegrees) {
    vector<vector<int>> graph(num, vector<int>());
    for (vector<int> edge : prerequisites) {
      int from = edge[1], to = edge[0];
      graph[from].push_back(to);
      ++indegrees[to];
    }
    return graph;
  }

  bool BFS(vector<vector<int>>& graph, vector<int>& indegrees, int num) {
    queue<int> q;
    for (int i = 0; i < num; ++i) {
      if (indegrees[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int parent = q.front(); q.pop();
      --num;
      for (int child : graph[parent]) {
        --indegrees[child];
        if (indegrees[child] == 0) {
          q.push(child);
        }
      }
    }
    return num == 0;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegrees(numCourses, 0);
    vector<vector<int>> graph = convertToGraph(prerequisites, numCourses, indegrees);
    return BFS(graph, indegrees, numCourses);
  }
};
// @leet end
