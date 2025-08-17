// @leet start
#include <string>

using std::string;

class Solution {
public:
  string longestPalindrome(string s) {
    string longestSubstring {s[0]};
    int middle {0}, left {0}, right {0}, offset {1}, maxLength {1};
    // case 1, the number is even
    while (middle < s.size()) {
      int length {0};
      left = middle;
      right = middle + 1;
      while (right < s.size() && left >= 0 && s[right] == s[left]) {
        // length increase by 2
        length += 2;
        // move right forward, left backward
        ++right;
        --left;
      }
      if (maxLength < length) {
        maxLength = length;
        longestSubstring = s.substr(left + 1, length);
      }
      ++middle;
    }
    // case 2, the number is odd
    middle = 1;
    offset = 2;
    while (middle < s.size()) {
      int length {1};
      left = middle - 1;
      right = middle + 1;
      while (right < s.size() && left >= 0 && s[right] == s[left]) {
        length += 2;
        ++right;
        --left;
      }
      if (maxLength < length) {
        maxLength = length;
        longestSubstring = s.substr(left + 1, length);
      }
      ++middle;
    }
    return longestSubstring;
  }
};
// @leet end
