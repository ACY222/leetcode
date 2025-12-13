// @leet start
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        // dp[i]: if s[0]-s[i - 1] can be broken
        vector<bool> dp(s.size() + 1, false);
        int maxWordLength = 0;
        for (auto& word : wordDict) {
            maxWordLength = max(maxWordLength, (int)word.size());
        }
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0 and (i - j) <= maxWordLength; --j) {
                if (dp[j] == true and wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// @leet end
