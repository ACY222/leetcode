// @leet start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<int>> dp;

    void dynamic_programming(string& t1, string& t2) {
        for (int row = 1; row <= m; ++row) {
            for (int col = 1; col <= n; ++col) {
                if (t1[row - 1] == t2[col - 1]) {
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                }
                else {
                    dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
                }
            }
        }
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        this->m = text1.size();
        this->n = text2.size();
        dp.resize(m + 1, vector<int>(n + 1, 0));
        dynamic_programming(text1, text2);
        return dp[m][n];
    }
};
// @leet end
