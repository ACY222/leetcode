// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    // p contains:
    //  1. single char: matches a single char
    //  2. (char)*: matches any number of char
    //  3. .*: matches any number of any chars
    bool isMatch(string s, string p) {
        auto s_size{s.size()}, p_size{p.size()};
        // dp[i][j] means if s[0-i] matches p[0-j]
        vector<vector<bool>> dp(s_size + 1, vector<bool>(p_size + 1, false));
        dp[0][0] = true;

        // "a*b*" can match with ""
        for (auto j = 2; j <= p_size; ++j) {
            if (p[j - 1] == '*') { dp[0][j] = dp[0][j - 2]; }
        }

        for (auto i{1}; i <= s_size; ++i) {
            for (auto j{1}; j <= p_size; ++j) {
                if (p[j - 1] == '*') {
                    // match 0 times
                    dp[i][j] = dp[i][j - 2];

                    // match 1 or more times
                    if (s[i - 1] == p[j - 2] or p[j - 2] == '.') {
                        // dp[i - 1][j - 2] true -> dp[i - 1][j] -> true
                        // -> dp[i][j] true
                        // dp[i][j] = dp[i][j] || dp[i - 1][j - 2];
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else { // letters or .
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
