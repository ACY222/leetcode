// @leet start
#include <vector>
using std::vector;
class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> diff(n, 0);
    int m {(int)bookings.size()};
    for (int i = 0; i < m; ++i) {
      // note that the given bookings is 1-based, and my vector is 0-based
      int from {bookings[i][0] - 1}, to {bookings[i][1]}, seats {bookings[i][2]};
      diff[from] += seats;
      if (to != n) {
        diff[to] -= seats;
      }
    }
    for (int i = 1; i < n; ++i) {
      diff[i] = diff[i - 1] + diff[i];
    }
    return diff;
  }
};
// @leet end
