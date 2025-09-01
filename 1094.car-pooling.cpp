// @leet start
#include <algorithm>
#include <utility>
#include <vector>
using std::vector;
using std::pair, std::sort;
class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<pair<int, int>> onAndOff;
    int n {(int)trips.size()};
    for (int i = 0; i < n; ++i) {
      onAndOff.push_back({trips[i][1], trips[i][0]});
      onAndOff.push_back({trips[i][2], -trips[i][0]});
    }
    sort(onAndOff.begin(), onAndOff.end());
    int numOfPassengers {0};
    n = onAndOff.size();
    for (int i = 0; i < n; ++i) {
      numOfPassengers += onAndOff[i].second;
      if (numOfPassengers > capacity) {
        return false;
      }
    }
    return true;
  }
};
// @leet end
