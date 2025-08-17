// @leet start
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) {
      return false;
    }
    // the length of the substring is s1.size(), so only the offset matters
    // need contains what we want, and window contains what we have
    vector<int> need(26, 0), window(26, 0);
    int left {0}, right {0};
    // initialize the vectors and then compare between them
    for (; right < s1.size(); ++right) {
      ++need[s1[right] - 'a'];
      ++window[s2[right] - 'a'];
    }
    if (need == window) {
      return true;
    }
    // using the sliding window
    for (; right < s2.size(); ++right, ++left) {
      // move window forward
      ++window[s2[right] - 'a'];
      --window[s2[left] - 'a'];
      if (need == window) {
        return true;
      }
    }
    return false;
  }
};
// @leet end
