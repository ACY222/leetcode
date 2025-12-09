#include <vector>
#include <array>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    int count;

    // initializing the union find based on the grid
    UnionFind(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        count = 0;
        parent.resize(m * n, -1);

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                // skip if no island
                if (grid[row][col] == '0') {
                    continue;
                }
                // grid[row][col] == '1'
                parent[row * n + col] = row * n + col;
                ++count;
            }
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int root_x = find(x), root_y = find(y);

        if (root_x != root_y) {
            parent[root_x] = root_y;
            --count;
        }
    }
};

class Solution {
private:
    inline bool outside(int row, int col, int m, int n) {
        return row < 0 or row >= m or col < 0 or col >= n;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        UnionFind uf(grid);

        int m = grid.size(), n = grid[0].size(), count = 0;
        array<array<int, 2>, 2> dirs = {{
            {0, 1}, {1, 0}
        }};

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == '0') {
                    continue;
                }
                for (auto& dir : dirs) {
                    int new_row = row + dir[0], new_col = col + dir[1];
                    if (new_row < m and new_col < n and grid[new_row][new_col] == '1') {
                        uf.unite(row * n + col, new_row * n + new_col);
                    }
                }
            }
        }

        return uf.count;
    }
};