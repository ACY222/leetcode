// @leet start
#include <string>
#include <vector>
#include <map>

using std::string, std::vector;
using std::map;

class Solution {
public:
  // an elegant solution I found in Leetcode
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> indices;

    int wordLength, wordNum;
    wordLength = words[0].size();
    wordNum = words.size();

    // if s is not long enough, return an empty vector
    if (s.size() < wordLength * wordNum) {
      return {};
    }

    // initialize wordsMap, used to record the word frequency in words
    map<string, int> wordsWeWant {}, wordsWeFound {};
    for (auto &word : words) {
      wordsWeWant[word]++;
    }

    for (int offset {0}; offset < wordLength; ++offset) {
      wordsWeFound.clear();
      // start is the beginning of current word
      int windowSize {0};
      for (int start {offset}; start <= s.size() - wordLength; start += wordLength) {
        // substring is the current word
        string substring {s.substr(start, wordLength)};
        auto iter {wordsWeWant.find(substring)};
        // if the substring is not the word we look for
        // this sliding window is invalid, so move start forward
        if (iter == wordsWeWant.end()) {
          wordsWeFound.clear();
          windowSize = 0;
          continue;
        }
        // otherwise
        wordsWeFound[substring]++;
        windowSize++;
        // if we have more word than we need, we need to move the window forward
        while (wordsWeFound[substring] > iter->second) {
          string firstWord {s.substr(start - (windowSize - 1) * wordLength, wordLength)};
          wordsWeFound[firstWord]--;
          windowSize--;
        }
        if (windowSize == wordNum) {
          indices.push_back(start - (windowSize - 1) * wordLength);
        }
      }
    }
    return indices;
  }
};
// @leet end
