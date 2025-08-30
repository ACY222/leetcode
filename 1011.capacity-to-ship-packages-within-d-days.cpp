// @leet start
#include <vector>
using std::vector;
class Solution {
public:
  int shipWithinDays(vector<int>& weights, int days) {
    int n {(int)weights.size()}, sumWeights {0}, lower, higher, remainDays {days}, middle;
    for (int i = 0; i < n; ++i) {
      sumWeights += weights[i];
    }
    lower = sumWeights / days;
    higher = sumWeights;
    while (higher > lower) {
      middle = lower + (higher - lower) / 2;
      if (greedyLoadingMethod(weights, days, middle)) {
        higher = middle;
      }
      else {
        lower = middle + 1;
      }
    }
    return lower;
  }
private:
  bool greedyLoadingMethod(vector<int>& weights, int days, int capacity) {
    for (int i = 0, remainCapacity, j = 0; i < days; ++i) {
      remainCapacity = capacity;
      while (j < weights.size() && remainCapacity >= weights[j]) {
        remainCapacity -= weights[j];
        ++j;
      }
      if (j == weights.size()) {
        return true;
      }
    }
    return false;
  }
};
// @leet end
