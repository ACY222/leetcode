// @leet start
#include <algorithm>
#include <unordered_map>
#include <vector>
using std::vector;
using std::unordered_map;
using std::max;
class Solution {
public:
  int maxJumps(vector<int>& arr, int d) {
    unordered_map<int, vector<int>> indexToAccessibleDest { findAccessibleDestinations(arr, d) };
    vector<int> jumps(arr.size(), 0);   // it records the maxJump for all pos
    vector<bool> visited(arr.size(), false);
    int maxJump {0};
    for (int index = 0; index < arr.size(); ++index) {
      int jump { maxJumpsForIndex(index, indexToAccessibleDest, visited, jumps) };
      maxJump = max(maxJump, jump);
    }
    return maxJump;
  }
private:
  // preprocess
  unordered_map<int, vector<int>> findAccessibleDestinations(vector<int> &arr, int d) {
    unordered_map<int, vector<int>> indexToAccessibleDest {};
    for (int i = 0; i < arr.size(); ++i) {
      // find the valid indices to go backward
      for (int j = 1; j <= d; ++j) {
        // if the destination is valid
        if (i - j >= 0 && arr[i] > arr[i - j]) {
          indexToAccessibleDest[i].push_back(i - j);
        }
        else {    // if the destination is out of range or the value is bigger
          break;  // stop exploring backward
        }
      }
      // find the valid indices to go forward
      for (int j = 1; j <= d; ++j) {
        // if the destination is valid
        if (i + j < arr.size() && arr[i] > arr[i + j]) {
          indexToAccessibleDest[i].push_back(i + j);
        }
        else {    // if the destination is out of range or the value is bigger
          break;  // stop exploring forward
        }
      }
    }
    return indexToAccessibleDest;
  }
  int maxJumpsForIndex(int index, unordered_map<int, vector<int>> &indexToAccessibleDest, vector<bool> &visited, vector<int> &jumps) {
    if (visited[index]) {     // if we have visited this index, return the jumps
      return jumps[index];
    }
    visited[index] = true;
    if (indexToAccessibleDest[index].empty()) {   // it cannot jump to other pos
      jumps[index] = 1;
      return 1;       // so the jump must be 1
    }
    // if it can jump to some postions
    int maxJump {0};
    for (auto child : indexToAccessibleDest[index]) {
      int jump {maxJumpsForIndex(child, indexToAccessibleDest, visited, jumps)};
      maxJump = max(maxJump, jump + 1);
    }
    jumps[index] = maxJump;
    return maxJump;
  }
};
// @leet end
