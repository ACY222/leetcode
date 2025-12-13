// @leet start
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    int m, n;
    vector<int> dp;

public:
    int minDistance(string word1, string word2) {
        this->m = word1.size();
        this->n = word2.size();
        if (m < n) {
            return minDistance(word2, word1);
        }

        dp.resize(n + 1);
        iota(dp.begin(), dp.end(), 0);

        for  (int i = 1; i <= m; ++i) {
            int prev = dp[0];   // prev will be dp[i - 1][j - 1]
            dp[0] = i;
            for (int j = 1; j <= n; ++j) {
                int curr = dp[j];   // curr is dp[i - 1][j]
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev;
                }
                else {
                    dp[j] = min({
                        prev + 1,   // replace
                        curr + 1,   // remove
                        dp[j-1] + 1,// insert
                    });
                }
                prev = curr;
            }
        }
        return dp[n];
    }
};
// @leet end
