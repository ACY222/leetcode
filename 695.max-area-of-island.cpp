// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
private:
    int m, n, maxSquare = 0;
    const int mark = 2;
    const vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    inline bool outside(int row, int col) {
        return row < 0 or row >= m or col < 0 or col >= n;
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
        // the position might be water, or has been visited
        if (grid[row][col] != 1) {
            return 0;
        }
        int square = 1; // current position
        grid[row][col] = mark;
        for (auto& dir : dirs) {
            int newRow = row + dir[0], newCol = col + dir[1];
            if (outside(newRow, newCol)) {
                continue;
            }
            square += dfs(grid, newRow, newCol);
        }
        return square;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    maxSquare = max(maxSquare, dfs(grid, i, j));
                }
            }
        }
        return maxSquare;
    }
};
// @leet end
