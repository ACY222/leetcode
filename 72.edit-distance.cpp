// @leet start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<int>> memo;

    int dp(const string& w1, const string& w2, int i, int j) {
        // if i == -1 and j == -1, return 0, bingo
        if (i == -1) return j + 1;
        if (j == -1) return i + 1;

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // if they are same
        if (w1[i] == w2[j]) {
            memo[i][j] = dp(w1, w2, i - 1, j - 1);  // skip
        }
        // if they are different
        else {
            memo[i][j] = min({
                dp(w1, w2, i - 1, j - 1) + 1,   // replace
                dp(w1, w2, i, j - 1) + 1,       // insert
                dp(w1, w2, i - 1, j) + 1        // delete
            });
        }
        return memo[i][j];
}

public:
    int minDistance(string word1, string word2) {
        this->m = word1.size();
        this->n = word2.size();
        memo.resize(m, vector<int>(n, -1)); // -1 to indicate unvisited

        return dp(word1, word2, m - 1, n - 1);
    }
};
// @leet end
