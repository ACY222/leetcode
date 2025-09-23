// @leet start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    int m, n;
    vector<vector<int>> dp;

    void init(const string& w1, const string& w2) {
        this->m = w1.size();
        this->n = w2.size();
        dp.resize(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
    }

public:
    int minDistance(string word1, string word2) {
        init(word1, word2);

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // if we don't need to delete current chars
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min({
                        dp[i - 1][j] + 1,
                        dp[i][j - 1] + 1
                    });
                }
            }
        }
        return dp[m][n];
    }
};
// @leet end
