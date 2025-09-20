// @leet start
#include <utility>
#include <vector>
using namespace std;
class Solution {
private:
    int m, n, num_empty = 0, num_ways = 0;
    pair<int, int> start, end;
    using vec = vector<vector<int>>;
    const vec dirs = {{0,-1},{0,1},{-1,0},{1,0}};
    const int mark = -2;

    void initialize(const vec& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++num_empty;
                }
                else if (grid[i][j] == 1) {
                    start = make_pair(i, j);
                }
                else if (grid[i][j] == 2) {
                    end = make_pair(i, j);
                }
            }
        }
    }

    inline bool outside(int row, int col) {
        return row < 0 or row >= m or col < 0 or col >= n;
    }

    void traverse(vec& grid, int count, int r, int c) {
        for (const auto& dir : dirs) {
            int row = r + dir[0], col = c + dir[1];
            if(outside(row, col)) {
                continue;
            }
            // if it's an empty square, mark and traverse to it
            if (grid[row][col] == 0) {
                grid[row][col] = mark;
                traverse(grid, count - 1, row, col);
                grid[row][col] = 0;
            }
            // if the end is the last square, the it's a new path
            else if (grid[row][col] == 2 and count == 0) {
                ++num_ways;
            }
            // otherwise, it would be the start square,
            // the obstacle, or visited empty square
        }
    }

public:
    // 1: start, 2: end, 0: where we can walk, -1: obstacle
    // return the way we can walk from start to end, and passing
    // by all the empty squares once
    int uniquePathsIII(vector<vector<int>>& grid) {
        initialize(grid);
        traverse(grid, num_empty, start.first, start.second);
        return num_ways;
    }
};
// @leet end
