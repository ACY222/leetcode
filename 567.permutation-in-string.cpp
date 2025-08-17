// @leet start
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) {
      return false;
    }
    // the length of the substring is s1.size(), so only the offset matters
    // need contains what we want, and window contains what we have
    unordered_map<char, int> need {}, window {};
    int left {0}, right {0};
    // initialize the map need and window
    for (; right < s1.size(); ++right) {
      ++need[s1[right]];
      ++window[s2[right]];
    }
    for (; right < s2.size(); ++right, ++left) {
      // if two map match, return true
      if (need == window) {
        return true;
      }
      ++window[s2[right]];
      --window[s2[left]];
      if (window[s2[left]] == 0) {
        window.erase(s2[left]);
      }
    }
    if (need == window) {
      return true;
    }
    return false;
  }
};
// @leet end
