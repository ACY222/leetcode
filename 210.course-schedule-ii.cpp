// @leet start
#include <queue>
#include <vector>
using std::queue;
using std::vector;
class Solution {
private:
  vector<bool> onPath;
  vector<int> indegrees;

  vector<vector<int>> generateGraph(vector<vector<int>>& edges, int num) {
    vector<vector<int>> graph(num, vector<int>());
    for (vector<int> edge : edges) {
      int to = edge[0], from = edge[1];
      graph[from].push_back(to);
      ++indegrees[to];
    }
    return graph;
  }

  vector<int> traverse(vector<vector<int>>& graph, int num) {
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
      --num;    // used to check if there is a cycle
      for (int child : graph[parent]) {
        --indegrees[child];
        if (indegrees[child] == 0) {
          q.push(child);
        }
      }
    }
    if (num == 0) {
      return res;
    }
    return {};
  }


public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    indegrees.resize(numCourses, 0);
    vector<vector<int>> graph = generateGraph(prerequisites, numCourses);
    return traverse(graph, numCourses);
  }
};
// @leet end
