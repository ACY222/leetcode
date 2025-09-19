// @leet start
#include <vector>
using namespace std;
class Solution {
private:
    int m, n, count = 0;
    const char mark = '2';
    const vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    inline bool outside(int row, int col) {
        return row < 0 or row >= m or col < 0 or col >= n;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (grid[row][col] != '1') {
            return;
        }
        grid[row][col] = mark;
        for (auto& dir : dirs) {
            int newRow = row + dir[0], newCol = col + dir[1];
            if (outside(newRow, newCol)) {
                continue;
            }
            dfs(grid, newRow, newCol);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
};
// @leet end
