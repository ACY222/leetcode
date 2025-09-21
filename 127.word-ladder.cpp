// @leet start
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int step = 1;
    vector<bool> visited;

    int findIndexOfEndWord(string& endWord, vector<string>& wordList) {
        for (int i = wordList.size() - 1; i >= 0; --i) {
            if (wordList[i] == endWord) {
                return i;
            }
        }
        return -1;
    }

    bool canTransform(string& curr, string& next) {
        int diff = 0;
        for (int i = 0; i < curr.size(); ++i) {
            if (curr[i] != next[i]) {
                if (++diff >= 2) {
                    return false;
                }
            }
        }
        return diff == 1;
    }

    // return true if we have found the endWord
    bool pushValidWords(queue<string>& q, string& curr,
                        int index, vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            if (canTransform(curr, wordList[i])) {
                visited[i] = true;
                if (i == index) {
                    return true;
                }
                q.push(wordList[i]);
            }
        }
        return false;
    }

    void bfs(string& begin, int index,  vector<string>& wordList) {
        queue<string> q;
        q.push(begin);

        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; --size) {
                auto curr = q.front();
                q.pop();
                if (pushValidWords(q, curr, index, wordList)) {
                    return;
                }
            }
        }
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int index {findIndexOfEndWord(endWord, wordList)};
        if (index == -1) {
            return 0;
        }
        visited.resize(wordList.size());
        bfs(beginWord, index, wordList);
        if (!visited[index]) {
            return 0;
        }
        return step;
    }
};
// @leet end
