// @leet start
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size(), p_size = p.size();
        vector<vector<bool>> dp(s_size + 1, vector<bool>(p_size + 1, false));
        dp[0][0] = true;

        // 'a*b*' == ''
        for (int j = 2; j <= p_size; j += 2) {
            if (p[j - 1] == '*') {
                dp[0][j] = true;
            } else {
                break;
            }
        }

        // `.`, `*`, and simple characters
        for (int i = 1; i <= s_size; ++i) {
            for (int j = 1; j <= p_size; ++j) {
                if (p[j - 1] == '*') {
                    // matches 0 chars
                    dp[i][j] = dp[i][j - 2];

                    // matches 1 or more chars
                    if (s[i - 1] == p[j - 2] or p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] or dp[i - 1][j];
                    }
                } else {
                    if (s[i - 1] == p[j - 1] or p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }

        return dp[s_size][p_size];
    }
};
// @leet end
