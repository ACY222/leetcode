// @leet start
#include <vector>
using namespace std;

class Solution {
private:
    int m, n, count = 0;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<bool>> visited;
    void DFS(const vector<vector<int>>& grid, int row, int col) {
        if (row < 0 or row >= m or col < 0 or col >= n)
            return;
        if (grid[row][col] == 1 or visited[row][col])
            return;

        visited[row][col] = true;
        for (const auto& dir : dirs) {
            DFS(grid, row + dir[0], col + dir[1]);
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            DFS(grid, i, 0);
            DFS(grid, i, n - 1);
        }
        for (int j = 1; j < n - 1; ++j) {
            DFS(grid, 0, j);
            DFS(grid, m - 1, j);
        }

        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0 and !visited[i][j]) {
                    ++count;
                    DFS(grid, i, j);    // visit all its neibours
                }
            }
        }
        return count;
    }
};
// @leet end
