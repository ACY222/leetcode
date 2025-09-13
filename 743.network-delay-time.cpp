// @leet start
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct Node {
  int index, dist;

  Node(int _index, int _dist) : index(_index), dist(_dist) {}

  // reload the operatro so that priority_queue is a min-heap
  bool operator<(const Node& other) const {
    return dist > other.dist;
  }

};
class Solution {
private:
  using Graph = vector<vector<pair<int, int>>>;

  Graph convertToGraph(vector<vector<int>>& distances, int n) {
    Graph graph(n + 1);
    for (auto& e : distances) { // e = {from, to, dist}
      graph[e[0]].emplace_back(e[1], e[2]);
    }
    return graph;
  }

  int Dijkstra(priority_queue<Node>& pq, Graph& graph, vector<int>& distance) {
    int visited = 0;  // count how many nodes are visited
    while (!pq.empty()) {
      Node curr = pq.top(); pq.pop();
      if (distance[curr.index] != -1) {
        continue; // the node is visited, skip it
      }
      // update curr's distance, and push its children into the queue
      distance[curr.index] = curr.dist;
      ++visited;
      for (auto& [to, dist] : graph[curr.index]) {
        pq.emplace(to, dist + curr.dist);
      }
    }
    return visited;
  }

public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<int> distance(n + 1, -1);  // therefore, -1 indicates unvisited
    Graph graph = convertToGraph(times, n);
    priority_queue<Node> pq;
    pq.emplace(k, 0);   // start from k, so the distance is 0
    // check if all nodes are visited
    if (Dijkstra(pq, graph, distance) < n) {
      return -1;
    }
    return *max_element(distance.begin(), distance.end());
  }
};
// @leet end
