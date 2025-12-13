// @leet start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // make sure n is smaller
        if (m < n) return minDistance(word2, word1);
        vector<int> dp(n + 1);
        for (int j = 1; j <= n; ++j) {
            dp[j] = j;
        }

        for (int i = 1; i <= m; ++i) {
            int prev = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; ++j) {
                int curr = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev;
                }
                else {
                    dp[j] = min({
                        dp[j] + 1,
                        dp[j - 1] + 1
                    });
                }
                prev = curr;
            }
        }
        return dp[n];
    }
};
// @leet end
