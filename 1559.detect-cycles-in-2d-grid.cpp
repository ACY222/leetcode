// @leet start
#include <utility>
#include <vector>
using namespace std;
class Solution {
private:
    const vector<pair<int, int>> dirs {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    bool dfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited,
             int px, int py, int cx, int cy) {
        visited[cx][cy] = true;

        for (auto& dir : dirs) {
            int nx = cx + dir.first, ny = cy + dir.second;

            if (nx >= grid.size() or nx < 0 or ny >= grid[0].size() or ny < 0
                or grid[nx][ny] != grid[cx][cy]) {
                continue;
            }

            // if visited(next)
            if (visited[nx][ny]) {
                // if next != parent, got it
                if (nx != px or ny != py) {
                    return true;
                } else {
                    continue;
                }
            }

            if (dfs(grid, visited, cx, cy, nx, ny)) { return true; }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (visited[x][y]) { continue; }
                if (dfs(grid, visited, -1, -1, x, y)) { return true; }
            }
        }

        return false;
    }
};
// @leet end
