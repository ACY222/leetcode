#include <vector>
#include <array>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size(), n = grid[0].size(), count = 0;
        array<array<int, 2>, 4> dirs = {{
            {0, -1}, {0, 1}, {1, 0}, {-1, 0}
        }};

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == '0') {
                    continue;
                }
                // if grid[row][col] == '1'
                queue<pair<int, int>> q;
                q.emplace(row, col);
                ++count;

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();

                    for (auto& dir : dirs) {
                        int new_row = r + dir[0];
                        int new_col = c + dir[1];
                        if (new_row < 0 or new_row >= m or new_col < 0 or new_col >= n) {
                            continue;
                        }
                        if (grid[new_row][new_col] == '0') {
                            continue;
                        }
                        grid[new_row][new_col] = '0';
                        q.emplace(new_row, new_col);
                    }
                }
            }
        }
        return count;
    }
};