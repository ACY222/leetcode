// @leet start
#include <vector>
using namespace std;

class Solution {
private:
    int m, n, count = 0;
    const int mark = 2;

    using vec = vector<vector<int>>;
    inline bool outside(int row, int col) {
        return row < 0 or row >= m or col < 0 or col >= n;
    }
    const vec dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool dfs(const vec& grid1, vec& grid2, int r, int c) {
        if (grid1[r][c] != 1) {
            return false;
        }

        grid2[r][c] = mark;
        bool isSub = true;
        for (const auto& dir : dirs) {
            int row = r + dir[0], col = c + dir[1];

            // if the pos is out of range
            if (outside(row, col) or grid2[row][col] != 1) {
                continue;
            }

            if (!dfs(grid1, grid2, row, col)) {
                isSub = false;
            }
        }
        return isSub;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    count += dfs(grid1, grid2, i, j);
                }
            }
        }
        return count;
    }
};
// @leet end
