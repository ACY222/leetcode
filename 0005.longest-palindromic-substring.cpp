// @leet start
#include <string>

using std::string;

class Solution {
public:
  string longestPalindrome(string s) {
    string res {};
    for (int i = 0; i < s.size(); ++i) {
      // use i as single center
      string s1 {palindromic(s, i, i)};
      // use i and i + 1 as double center
      string s2 {palindromic(s, i, i + 1)};
      res = res.size() > s1.size() ? res : s1;
      res = res.size() > s2.size() ? res : s2;
    }
    return res;
  }
private:
  string palindromic(string s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      ++right;
      --left;
    }
    return s.substr(left + 1, right - left - 1);
  }
};
// @leet end
