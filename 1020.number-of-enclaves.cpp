// @leet start
#include <vector>
using namespace std;
class Solution {
private:
    int m, n, count = 0;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<bool>> visited;

    void dfs(const vector<vector<int>>& grid, int row, int col) {
        // if this point is not in the grid
        if (row < 0 or row >= m or col < 0 or col >= n) {
            return;
        }
        // if it is not 1 or it has been visited
        if (grid[row][col] == 0 or visited[row][col]) return;
        visited[row][col] = true;
        for (const auto& dir : dirs) {
            dfs(grid, row + dir[0], col + dir[1]);
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        for (int j = 1; j < n - 1; ++j) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] == 1 and !visited[i][j]) {
                    ++count;
                }
            }
        }
        return count;
    }
};
// @leet end
