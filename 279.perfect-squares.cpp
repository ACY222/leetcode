// @leet start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp{0};

        while (dp.size() <= n) {
            int m = dp.size();
            int min_val = INT_MAX;

            for (int i = 1; i * i <= m; ++i) {
                min_val = min(min_val, dp[m - i * i] + 1);
            }
            dp.push_back(min_val);
        }
        return dp[n];
    }
};
// @leet end
