// @leet start
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
private:
    void initialize(const vector<vector<int>>& grid,
                    vector<vector<map<int, int>>>& dp, int k) {
        dp[0][0][0] = 0;

        for (int y = 1; y < grid[0].size(); ++y) {
            int curr_score = grid[0][y], curr_cost = (grid[0][y] == 0) ? 0 : 1;

            auto [last_cost, last_score] = *dp[0][y - 1].begin();
            int score = last_score + curr_score;
            int cost = last_cost + curr_cost;

            if (cost > k) { break; }
            dp[0][y][cost] = score;
        }

        for (int x = 1; x < grid.size(); ++x) {
            int curr_score = grid[x][0], curr_cost = (grid[x][0] == 0) ? 0 : 1;

            auto [last_cost, last_score] = *dp[x - 1][0].begin();
            int score = last_score + curr_score;
            int cost = last_cost + curr_cost;

            if (cost > k) { break; }
            dp[x][0][cost] = score;
        }
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // dp[x][y][c] = the max score at (x, y) with cost c
        vector<vector<map<int, int>>> dp(m, vector<map<int, int>>(n));

        initialize(grid, dp, k);

        for (int x = 1; x < m; ++x) {
            for (int y = 1; y < n; ++y) {
                int val = grid[x][y];
                int curr_score = val, curr_cost = (val == 0) ? 0 : 1;

                for (const auto [last_cost, last_score] : dp[x][y - 1]) {
                    int cost = last_cost + curr_cost,
                        score = last_score + curr_score;

                    // prune
                    if (cost > k) { break; }
                    dp[x][y][cost] = score;
                }

                for (const auto [last_cost, last_score] : dp[x - 1][y]) {
                    int cost = last_cost + curr_cost,
                        score = last_score + curr_score;
                    if (cost > k) { break; }

                    // if not found or less than score, update it
                    if (dp[x][y].find(cost) == dp[x][y].end()
                        or dp[x][y][cost] < score) {
                        dp[x][y][cost] = score;
                    }
                }
            }
        }

        int max_score = -1;
        for (auto [cost, score] : dp[m - 1][n - 1]) {
            max_score = max(score, max_score);
        }

        return max_score;
    }
};
// @leet end
