// @leet start
#include <vector>
using std::vector;
class Solution {
public:
  // the difference array helps
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> diff(1001, 0);
    int n {(int)trips.size()};
    for (int i = 0; i < n; ++i) {
      int num {trips[i][0]}, from {trips[i][1]}, to {trips[i][2]};
      diff[from] -= num;
      diff[to] += num;
    }
    for (int i = 0; i <= 1000; ++i) {
      capacity += diff[i];
      if (capacity < 0) {
        return false;
      }
    }
    return true;
  }
};
// @leet end
