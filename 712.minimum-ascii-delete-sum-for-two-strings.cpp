// @leet start
#include <algorithm>
#include <string>
#include <vector>
using namespace  std;
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m < n) return minimumDeleteSum(s2, s1);

        vector<int> dp(n + 1);
        for (int j = 1; j <= n; ++j) {
            dp[j] = dp[j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= m; ++i) {
            int prev = dp[0];
            // this line is wrong
            dp[0] = prev + s1[i - 1];
            for (int j = 1; j <= n; ++j) {
                int curr = dp[j];
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = prev;
                }
                else {
                    dp[j] = min({
                        dp[j - 1] + s2[j - 1],
                        dp[j] + s1[i - 1]
                    });
                }
                prev = curr;
            }
        }
        return dp[n];
    }
};
// @leet end
