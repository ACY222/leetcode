// @leet start
#include <vector>
using std::vector;
class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int n {(int)trips.size()};
    vector<int> remainSeats(1000, capacity);
    for (int i = 0; i < n; ++i) {
      int num {trips[i][0]}, from {trips[i][1]}, to {trips[i][2]};
      for (int j = from; j < to; ++j) {
        if (remainSeats[j] < num) {
          return false;
        }
        remainSeats[j] -= num;
      }
    }
    return true;
  }
};
// @leet end
