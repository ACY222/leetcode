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
    // initialize the map need and window
    for (int i {0}; i < s1.size(); ++i) {
      ++need[s1[i]];
      ++window[s2[i]];
    }
    for (int offset = s1.size(); offset < s2.size(); ++offset) {
      // if two map match, return true
      if (need == window) {
        return true;
      }
      char toDelete {s2[offset - s1.size()]}, toInsert {s2[offset]};
      ++window[toInsert];
      --window[toDelete];
      if (window[toDelete] == 0) {
        window.erase(toDelete);
      }
    }
    if (need == window) {
      return true;
    }
    return false;
  }
};
// @leet end
