// @leet start
#include <vector>

using std::vector;

class Solution {
public:
  void reverseString(vector<char>& s) {
    int left {0}, right {(int)s.size() - 1};
    while (left < right) {
      char temp {s[right]};
      s[right] = s[left];
      s[left] = temp;
      ++left;
      --right;
    }
    return;
  }
};
// @leet end
