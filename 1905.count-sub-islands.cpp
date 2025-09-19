// @leet start
#include <vector>
using namespace std;
class Solution {
private:
    int m, n, count = 0;
    static constexpr int MARK = 2;
    const vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    inline bool outside(int row, int col) {
        return row < 0 or row >= m or col < 0 or col >= n;
    }
    bool dfs(const vector<vector<int>>& grid1, vector<vector<int>>& grid2,
             int row, int col) {
        if (grid1[row][col] != 1) {
            return false;
        }
        // we should mark the position after we know that grid1[row][col] == 1,
        // otherwise when we arrive the other part of this island in grid2,
        // we will mistakenly skip this position
        grid2[row][col] = MARK;
        bool isSub = true;

        for (auto& dir : dirs) {
            int newRow = row + dir[0], newCol = col + dir[1];
            // if the neighbor is outside the grid
            // or if the neighbor is not land(== 0)
            // or has been visited(==MARK)
            if (outside(newRow, newCol) or grid2[newRow][newCol] != 1) {
                continue;
            }
            // check neighbors
            if (!dfs(grid1, grid2, newRow, newCol)) {
                isSub = false;
            }
        }
        return isSub;
    }


public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        this->m = grid1.size();
        this->n = grid1[0].size();
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
