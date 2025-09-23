// @leet start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    int m, n;
    vector<vector<int>> memo;

    int dp(string& w1, string& w2, int r, int c) {
        if (r < 0) return c + 1;
        if (c < 0) return r + 1;

        if (memo[r][c] != 0) {
            return memo[r][c];
        }

        if (w1[r] == w2[c]) {
            memo[r][c] = dp(w1, w2, r - 1, c - 1);
        }
        else {
            memo[r][c] = min({
                dp(w1, w2, r - 1, c) + 1,
                dp(w1, w2, r, c - 1) + 1
            });
        }
        return memo[r][c];
    }

public:
    int minDistance(string word1, string word2) {
        this->m = word1.size();
        this->n = word2.size();
        memo.resize(m, vector<int>(n));
        return dp(word1, word2, m - 1, n - 1);
    }
};
// @leet end
