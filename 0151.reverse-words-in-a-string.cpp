// @leet start
#include <algorithm>
#include <string>
#include <utility>
using std::string;
using std::reverse, std::swap;
class Solution {
public:
  string reverseWords(string s) {
    // first remove all the extra spaces
    removeSpaces(s);
    // second reverse whole string
    reverse(s.begin(), s.end());
    // third reverse word one by one
    int n { (int)s.size() }, start {0};
    for (int i = 0; i <= n; ++i) {
      if (i == n || s[i] == ' ') {
        reverseWord(s, start, i);
        start = i + 1;
      }
    }
    return s;
  }

private:
  void reverseWord(string &s, int begin, int end) {
    while (end > begin) {
      swap(s[begin], s[end - 1]);
      ++begin; --end;
    }
    return;
  }
  void removeSpaces(string &s) {
    int n {(int)s.size()};
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == ' ') {    // if we find a space, try to find more
        int j {i - 1};
        while (j >= 0 && s[j] == ' ') {
          --j;
        }
        if (j <= i - 1) {    // if there is more than one space
          if (i == n - 1 || j == -1) { // if the spaces are at the beginning/end
            s.erase(j + 1, i - j);
          }
          else {            // if this is between two words
            s.erase(j + 1, i - j - 1);
          }
        }
        i = j;
      }
    }
  }
};
// @leet end
