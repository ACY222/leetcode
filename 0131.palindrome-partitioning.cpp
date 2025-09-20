// @leet start
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    int n;

    void initialize(const string& s, vector<vector<bool>>& dp) {
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int length = 2; length <= n; ++length) {
            for (int start = 0; start <= n - length; ++start) {
                int end = start + length - 1;
                if (s[start] == s[end] and
                    (length == 2 or dp[start + 1][end - 1])) {
                    dp[start][end] = true;
                }
            }
        }
    }

    void backtrack(const string& s, vector<string>& path,
                   const vector<vector<bool>>& dp, int start) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        for (int end = start; end < s.size(); ++end) {
            if (dp[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, path, dp, end + 1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<string> path;
        initialize(s, dp);
        backtrack(s, path, dp, 0);
        return res;
    }
};
// @leet end
