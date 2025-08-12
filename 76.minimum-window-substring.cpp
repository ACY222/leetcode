// @leet start
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
  string minWindow(string s, string t) {
    // if s is shorter than t, then there won't be the substring we want
    if (s.size() < t.size()) {
      return {};
    }
    // initialize the map chars we want
    unordered_map<char, int> charsWeWant {}, charsWeFound {};
    // minSize as the size of the substring, start as the offset
    // left, right as the sides of sliding window
    // matches as the count about how many chars two maps match
    int minSize {INT_MAX}, start {0}, left {0}, right {0}, matches;
    for (int i {0}; i < t.size(); ++i) {
      ++charsWeWant[t[i]];
    }
    // look for the substring in s
    while (right < s.size()) {
      char c {s[right]};    // this is the character to be added
      ++right;
      if (charsWeWant.count(c)) {
        ++charsWeWant[c];
        if (charsWeWant[c] == charsWeFound[c]) {
          ++matches;
        }
      }
      // if the matches satisfies, shrink the window(move left forward)
      while (matches == charsWeWant.size()) {
        // if current substring is shorter, update
        if (right - left < minSize) {
          minSize = right - left;
          start = left;
        }
        char d {s[left]};   // this is the character to be deleted
        ++left;
        if (charsWeWant.count(d)) { // if this character is needed
          // if we don't have enough characters without it
          if (charsWeWant[d] == charsWeFound[d]) {
            --matches;
          }
        }
      }
    }
    return s.substr(start, minSize);
  }
};
// @leet end
