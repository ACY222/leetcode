// @leet start
#include <algorithm>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using std::vector, std::sort;
using std::abs;
using std::pair, std::make_pair;
using std::unordered_map, std::string, std::to_string;

using Point = pair<int, int>;
// two points and the distance
using Edge = pair<pair<Point, Point>, int>;

class Solution {
private:
  unordered_map<string, int> pointToIndex;
  vector<Edge> edges {};
  vector<Point> indexToPoint {};
  vector<int> parent {}, size {};    // use indices instead of points

  string convertPointToString(Point& p) {
    return to_string(p.first) + '-' + to_string(p.second);
  }

  int getDistance(Point& p, Point& q) {
    return abs(p.first - q.first) + abs(p.second - q.second);
  }

  int find(Point& p) {
    int index = pointToIndex[convertPointToString(p)];
    while (parent[index] != index) {
      parent[index] = parent[parent[index]];
      index = parent[index];
    }
    return index;
  }

  // sort the edges by distance, initialize the parent, indexToPoint size, and
  // pointToIndex
  void preProcess(vector<vector<int>>& points, int num) {
    size.resize(num, 1);
    parent.reserve(num);
    indexToPoint.reserve(num);
    edges.reserve((num - 1) * num / 2);
    for (int i = 0; i < num; ++i) {
      Point p = make_pair(points[i][0], points[i][1]);
      parent.push_back(i);
      indexToPoint.push_back(p);
      pointToIndex[convertPointToString(p)] = i;
      for (int j = i + 1; j < num; ++j) {
        Point q = make_pair(points[j][0], points[j][1]);
        Edge edge = make_pair(make_pair(p, q), getDistance(p, q));
        edges.push_back(edge);
      }
    }
    auto compare = [](Edge& u, Edge&v) { return u.second < v.second; };
    // sort the edges by non-descending order
    sort(edges.begin(), edges.end(), compare);
  }

  bool connect(Point& p, Point& q) {
    int rootP = find(p), rootQ = find(q);
    if (rootP == rootQ) {
      return false;   // they are already connected
    }
    if (size[rootP] > size[rootQ]) {
      parent[rootQ] = rootP;
      size[rootP] += size[rootQ];
    }
    else {
      parent[rootP] = rootQ;
      size[rootQ] += size[rootP];
    }
    return true;
  }

public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int num = points.size(), numEdges = 0, totalDistance = 0;
    preProcess(points, num);

    for (auto iter = edges.begin(); iter != edges.end() and numEdges < num - 1; ++iter) {
      auto [p, q] = iter->first;
      if (connect(p, q)) {
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
