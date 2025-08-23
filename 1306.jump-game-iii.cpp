// @leet start
#include <queue>
#include <vector>
using std::vector;
using std::queue;
class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
    // use the vector flag to show if we have visited this element
    vector<bool> flag(arr.size(), false);
    // use the queue q to record the elements we just visited
    queue<int> q;
    q.push(start);
    flag[start] = true;
    while (!q.empty()) {
      int pos { q.front() };
      if (arr[pos] == 0) {
        return true;
      }
      q.pop();
      // if the index we can reach is valid and we haven't visited it
      int index1 { pos - arr[pos] }, index2 { pos + arr[pos] };
      if (index1 >= 0 && flag[index1] == false) {
        q.push(index1);
        flag[index1] = true;
      }
      if (index2 < arr.size() && flag[index2] == false) {
        q.push(index2);
        flag[index2] = true;
      }
    }
    return false;
  }
};
// @leet end
