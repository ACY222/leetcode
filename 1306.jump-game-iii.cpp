// @leet start
#include <unordered_map>
#include <vector>
using std::vector;
using std::unordered_map;
class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
    // we have reached this element and failed, now we reach it again, so failed
    if (flag[start] == true) {
      return false;
    }
    flag[start] = true;
    // no, I should solve this in above layer, so it won't overflow
    if (start < 0 || start >= arr.size()) {
      return false;
    }
    // if the value is 0, we have reached the destination
    if (arr[start] == 0) {
      return true;
    }
    if (start - arr[start] < 0) {
      if (start + arr[start] >= arr.size()) {
        return false;
      }
      return canReach(arr, start + arr[start]);
    }
    else {
      if (start + arr[start] >= arr.size()) {
        return canReach(arr, start - arr[start]);
      }
      return canReach(arr, start - arr[start]) || canReach(arr, start + arr[start]);
    }
  }
private:
  // using this map to record if we have reached this element, so that we can
  // avoid visiting one element again and again
  unordered_map<int, bool> flag;
};
// @leet end
