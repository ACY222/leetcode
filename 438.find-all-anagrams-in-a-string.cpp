// @leet start
#include <vector>
#include <string>
#include <array>

using std::vector, std::string;
using std::array;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) {
      return {};
    }
    vector<int> indices {};
    array<int, 26> freq_s {}, freq_p {};
    for (int i = 0; i < p.size(); ++i) {
      ++freq_s[s[i] - 'a'];
      ++freq_p[p[i] - 'a'];
    }
    if (freq_s == freq_p) {
      indices.push_back(0);
    }
    for (int i = p.size(); i < s.size(); ++i) {
      ++freq_s[s[i] - 'a'];
      --freq_s[s[i - p.size()] - 'a'];
      if (freq_s == freq_p) {
        indices.push_back(i - p.size() + 1);
      }
    }
    return indices;
  }
};
// @leet end
