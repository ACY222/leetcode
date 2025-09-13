// @leet start
#include <queue>
#include <utility>
#include <vector>
#include <ranges>
using namespace std;
class Solution {
private:
  using P = pair<int, int>;
  using Graph = vector<vector<pair<int, int>>>;

  int Dijkstra(const Graph& graph, vector<int>& dist, int maxMoves) {
    priority_queue<P, vector<P>, greater<>> minHeap;

    dist[0] = 0;
    minHeap.emplace(dist[0], 0);    // start at 0 and dist is 0

    while (!minHeap.empty()) {
      const auto [d, u] = minHeap.top();
      minHeap.pop();
      // already took maxMoves to reach the nearest node, so we cannot explore
      // more
      if (d >= maxMoves) {
        break;
      }
      for (const auto& [v, w] : graph[u]) {  // push all its unvisited children
        if (d + w + 1 < dist[v]) {
          dist[v] = d + w + 1;
          minHeap.emplace(dist[v], v);
        }
      }
    }

    return ranges::count_if(dist, [&](int d) { return d <= maxMoves; });
  }

public:
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    // initialize the graph and dist
    vector<int> dist(n, maxMoves + 1);
    Graph graph(n);
    for (const auto& edge : edges) {
      const int u = edge[0], v = edge[1], cnt = edge[2];
      graph[u].emplace_back(v, cnt);
      graph[v].emplace_back(u, cnt);
    }

    const int reachableNodes = Dijkstra(graph, dist, maxMoves);
    int reachableSubNodes = 0;

    for (const auto& edge : edges) {
      const int u = edge[0], v = edge[1], cnt = edge[2];
      // calcute the number of subnodes we can reach from either side
      int fromU = 0, fromV = 0;
      fromU = dist[u] > maxMoves ? 0 : min(maxMoves - dist[u], cnt);
      fromV = dist[v] > maxMoves ? 0 : min(maxMoves - dist[v], cnt);
      reachableSubNodes += min(fromU + fromV, cnt);
    }
    return reachableNodes + reachableSubNodes;
  }
};
// @leet end
