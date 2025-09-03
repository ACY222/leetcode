// @leet start
#include <algorithm>
#include <vector>
using std::vector;
using std::max_element;
class Solution {
public:
  // Koko can eat no more than one pile in an hour
  int minEatingSpeed(vector<int>& piles, int h) {
    int left {1}, right { *max_element(piles.begin(), piles.end()) + 1 }, mid;
    while (right > left) {
      mid = left + (right - left) / 2;
      if (canFinish(piles, mid, h)) {
        right = mid;
      }
      else {
        left = mid + 1;
      }
    }
    return left;
  }
private:
  bool canFinish(vector<int>& piles, int speed, int h) {
    int hours {0}, n {(int)piles.size()};
    for (int n : piles) {
      hours += timeOf(n, speed);
    }
    return hours <= h;
  }
  int timeOf(int n, int speed) {
    return (n / speed) + ((n % speed) > 0 ? 1 : 0);
  }
};
// @leet end
