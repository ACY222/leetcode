// @leet start
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
    int m, n, num = 0, time = 0;

    static constexpr int dx[4] = {0, 0, -1, 1};
    static constexpr int dy[4] = {-1, 1, 0, 0};


    void init(vector<vector<int>>& grid, vector<pair<int, int>>& rotten) {
        this->m = grid.size();
        this->n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // record the pos of rotten oranges and num of fresh oranges
                if (grid[i][j] == 2) {
                    rotten.push_back({i, j});
                }
                else if (grid[i][j] == 1) {
                    ++num;
                }
            }
        }
    }

    inline bool outside(int r, int c) {
        return (r < 0 or r >= m or c < 0 or c >= n);
    }

    bool bfs(vector<vector<int>>& grid, vector<pair<int, int>>& rotten) {
        queue<pair<int, int>> q;
        for (auto& orange : rotten) {
            q.push(orange);
        }

        while (!q.empty()) {
            ++time;
            for (int size = q.size(); size > 0; --size) {
                auto curr = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int r = curr.first + dx[i], c = curr.second + dy[i];
                    if (outside(r, c) or grid[r][c] != 1) {
                        continue;
                    }
                    // the fresh orange turn into rotten orange
                    grid[r][c] = 2;
                    // if all the fresh oranges got rotten
                    if (--num == 0) {
                        return true;
                    }
                    q.push({r, c});
                }
            }
        }
        return false;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> rotten;
        init(grid, rotten);
        if (num == 0) {
            return 0;
        }
        if (bfs(grid, rotten)) {
            return time;
        }
        return -1;
    }
};
// @leet end
