// @leet start
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <vector>
using std::vector, std::sort;
using std::abs;
using std::pair, std::make_pair;

using Point = pair<int, int>;
// the indices of two pointers and the distance
using Edge = pair<pair<int, int>, int>;

class Solution {
private:
  vector<Edge> edges {};
  vector<int> ufParent {};    // use indices instead of points

  int getDistance(Point& p, Point& q) {
    return abs(p.first - q.first) + abs(p.second - q.second);
  }

  int find(int x) {
    while (ufParent[x] != x) {
      x = ufParent[x];
    }
    return x;
  }

  // sort the edges by distance, initialize the parent, size
  void preProcess(vector<vector<int>>& points, int num) {
    ufParent.reserve(num);
    edges.reserve((num - 1) * num / 2);
    for (int i = 0; i < num; ++i) {
      Point p = make_pair(points[i][0], points[i][1]);
      ufParent.push_back(i);
      for (int j = i + 1; j < num; ++j) {
        Point q = make_pair(points[j][0], points[j][1]);
        Edge edge = make_pair(make_pair(i, j), getDistance(p, q));
        edges.push_back(edge);
      }
    }
    auto compare = [](Edge& u, Edge&v) { return u.second < v.second; };
    // sort the edges by non-descending order
    sort(edges.begin(), edges.end(), compare);
  }

  bool unite(int p, int q) {
    int rootP = find(p), rootQ = find(q);
    if (rootP == rootQ) {
      return false;   // they are already connected
    }
    ufParent[rootQ] = rootP;
    return true;
  }

public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int num = points.size(), numEdges = 0, totalDistance = 0;
    preProcess(points, num);

    for (auto iter = edges.begin(); iter != edges.end() and numEdges < num - 1; ++iter) {
      auto [p, q] = iter->first;
      if (unite(p, q)) {
        ++numEdges;
        totalDistance += iter->second;
      }
      else {
      }
    }
    return totalDistance;
  }
};
// @leet end
