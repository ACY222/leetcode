// @leet start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int m, n;

public:
    int minDistance(string word1, string word2) {
        this->m = word1.size();
        this->n = word2.size();
        // make sure n is the shorter length
        if (m < n) return minDistance(word2, word1);

        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            dp[i] = i;
        }

        for (int i = 1; i <= m; ++i) {
            // prev stores the value in dp[i - 1][j - 1]
            int prev = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; ++j) {
                int curr = dp[j];   // for prev in next loop
                if (word1[i - 1] == word2[j - 1]) {
                    // dp[i][j] = dp[i - 1][j - 1]
                    dp[j] = prev;
                }
                else {
                    dp[j] = min({
                        // dp[i - 1][j - 1] + 1,
                        // dp[i - 1][j] + 1,
                        // dp[i][j - 1] + 1,
                        prev + 1,
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
