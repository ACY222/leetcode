// @leet start
#include <unordered_map>
#include <vector>
using std::vector;
using std::unordered_map;
class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
    // we have reached this element and failed
    if (flag[start] == true) {
      return false;
    }
    flag[start] = true;
    if (start < 0 || start >= arr.size()) {
      return false;
    }
    if (arr[start] == 0) {
      return true;
    }
    return canReach(arr, start - arr[start]) || canReach(arr, start + arr[start]);
  }
private:
  // using this map to record if we have reached this element, so that we can
  // avoid visiting one element again and again
  unordered_map<int, bool> flag;
};
// @leet end
