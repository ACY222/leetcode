// @leet start
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using type_dp = vector<vector<vector<pair<int, int>>>>;
using type_grid = vector<vector<int>>;

class Solution {
private:
    void from_left(const type_dp& dp, const type_grid& grid, int x, int y) {}

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // dp[x][y][c] = the max score at (x, y) with cost c
        vector<vector<unordered_map<int, int>>> dp(
            m, vector<unordered_map<int, int>>(n)
        );

        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                int val = grid[x][y];
                int curr_score = val, curr_cost = (val == 0) ? 0 : 1;

                if (x == 0 and y == 0) { dp[x][y][curr_cost] = curr_score; }

                if (y > 0) {
                    for (const auto [last_cost, last_score] : dp[x][y - 1]) {
                        int cost = last_cost + curr_cost,
                            score = last_score + curr_score;
                        dp[x][y][cost] = score;
                    }
                }
                if (x > 0) {
                    for (const auto [last_cost, last_score] : dp[x - 1][y]) {
                        int cost = last_cost + curr_cost,
                            score = last_score + curr_score;

                        // if not found or less than score, update it
                        if (dp[x][y].find(cost) == dp[x][y].end()
                            or dp[x][y][cost] < score) {
                            dp[x][y][cost] = score;
                        }
                    }
                }
            }
        }

        int max_score = -1;
        for (auto [cost, score] : dp[m - 1][n - 1]) {
            if (cost <= k) { max_score = max(score, max_score); }
        }

        return max_score;
    }
};
// @leet end
