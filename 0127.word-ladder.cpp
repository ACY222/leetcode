// @leet start
#include <queue>
#include <string>
#include <utility>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            auto [word, step] = q.front();
            q.pop();
            // if current word is endWord
            if (word == endWord) {
                return step;
            }
            for (int i = 0; i < word.size(); ++i) {
                string temp = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    temp[i] = ch;
                    if (wordSet.count(temp)) {
                        q.push({temp, step + 1});
                        wordSet.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
// @leet end
