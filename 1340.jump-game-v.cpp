// @leet start
#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;
using std::max, std::min;
using std::cout, std::endl;
class Solution {
public:
  int maxJumps(vector<int>& arr, int d) {
    vector<vector<int>> reacheableDestinations { findReacheableDestinations(arr, d) };
    // we can use the value of jumps to show if we have visited the element
    // if the corresponding jump is not 0, then we have visited it
    vector<int> jumps(arr.size(), 0);   // it records the maxJump for all pos
    int maxJump {0};
    for (int index = 0; index < arr.size(); ++index) {
      maxJump = max(maxJumpsForIndex(index, reacheableDestinations, jumps), maxJump);
    }
    return maxJump;
  }
private:
  // preprocess
  vector<vector<int>> findReacheableDestinations(vector<int> &arr, int d) {
    vector<vector<int>> reacheableDestinations(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
      // find the valid indices to go backward
      for (int j = 1; j <= min(d, i); ++j) {
        // if the destination is valid
        if (arr[i] <= arr[i - j]) {
          break;
        }
        reacheableDestinations[i].push_back(i - j);
      }
      // find the valid indices to go forward
      for (int j = 1; j <= min(d, (int)arr.size() - i - 1); ++j) {
        // if the destination is valid
        if (arr[i] <= arr[i + j]) {
          break;
        }
        reacheableDestinations[i].push_back(i + j);
      }
    }
    return reacheableDestinations;
  }
  int maxJumpsForIndex(int index, vector<vector<int>> &indexToAccessibleDest, vector<int> &jumps) {
    if (jumps[index] != 0) {      // if we have visited this index, return the jumps
      return jumps[index];
    }
    jumps[index] = 1;             // we can visit itself, so at least 1
    // if it can jump to some postions
    for (auto child : indexToAccessibleDest[index]) {
      int jump {maxJumpsForIndex(child, indexToAccessibleDest, jumps)};
      jumps[index] = max(jumps[index], jump + 1);
    }
    return jumps[index];
  }
};
// @leet end
