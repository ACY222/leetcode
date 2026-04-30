// @leet start
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k = min(k, m + n - 1);
        // dp[j][c] = max score in cell (curr_row, col j) with exact cost c
        // initialized with -1 means irreachable
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        dp[0][0] = 0;
        for (int j = 1; j < n; ++j) {
            int val = grid[0][j];
            int cost = (val == 0) ? 0 : 1, score = val;

            for (int last_cost = 0; last_cost + cost <= k; ++last_cost) {
                int last_score = dp[j - 1][last_cost];

                if (last_score != -1) {
                    dp[j][last_cost + cost] = last_score + score;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            vector<vector<int>> next_dp(n, vector<int>(k + 1, -1));

            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                int cost = (val == 0) ? 0 : 1, score = val;

                for (int last_cost = 0; last_cost + cost <= k; ++last_cost) {
                    int max_last_score = -1;
                    // move from above cell
                    if (dp[j][last_cost] != -1) {
                        max_last_score = dp[j][last_cost];
                    }

                    // move from left cell
                    if (j > 0 and next_dp[j - 1][last_cost] != -1) {
                        max_last_score =
                            max(next_dp[j - 1][last_cost], max_last_score);
                    }

                    if (max_last_score != -1) {
                        next_dp[j][last_cost + cost] = max_last_score + score;
                    }
                }
            }
            dp = std::move(next_dp);
        }

        int max_score = -1;
        for (auto score : dp[n - 1]) {
            max_score = max(score, max_score);
        }
        return max_score;
    }
};
// @leet end
