// @leet start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<int>> dp;

    void init() {
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
    }

public:
    int minDistance(string word1, string word2) {
        this->m = word1.size();
        this->n = word2.size();
        dp.resize(m + 1, vector<int>(n + 1));
        init();

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min({
                        dp[i - 1][j] + 1,   // delete
                        dp[i - 1][j - 1] + 1,// replace
                        dp[i][j - 1] + 1    // insert
                    });
                }
            }
        }
        return dp[m][n];
    }
};
// @leet end
