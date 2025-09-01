// @leet start
#include <vector>
using std::vector;
class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int n {(int)trips.size()};
    vector<int> remainSeats(1000, capacity);
    for (int i = 0; i < n; ++i) {
      for (int j = trips[i][1], num = trips[i][0]; j < trips[i][2]; ++j) {
        remainSeats[j] -= num;
      }
    }
    for (int seats : remainSeats) {
      if (seats < 0) {
        return false;
      }
    }
    return true;
  }
};
// @leet end
