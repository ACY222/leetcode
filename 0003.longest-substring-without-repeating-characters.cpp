// @leet start
#include <string>
#include <set>
#include <algorithm>

using std::string;
using std::set;
using std::max;

class Solution {

public:
  int lengthOfLongestSubstring(string s) {
    set<char> contents {};
    int left {0}, right {0}, maxLength {0};
    while (left < s.size() && right < s.size()) {
      // if we can find s[right] in the set, keep moving left forward
      while (contents.find(s[right]) != contents.end()) {
        contents.erase(s[left]);
        ++left;
      }
      // now we cannot find s[right] in the set, it's a legal case
      contents.insert(s[right]);
      ++right;
      maxLength = max(maxLength, right - left);
    }
    return maxLength;
  }
};
// @leet end
