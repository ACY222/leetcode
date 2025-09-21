// @leet start
#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
    int n, step = 1;

    static constexpr int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
    static constexpr int dy[8] = {-1, 1, 0, 0, -1, 1, 1, -1};

    inline bool outside(int r, int c) {
        return (r < 0 or r >= n or c < 0 or c >= n);
    }

    inline bool isEnd(int r, int c) {
        return (r == n - 1 and c == n - 1);
    }

    bool bfs(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; --size) {
                auto top = q.front();
                q.pop();
                // eight directions
                for (int i = 0; i < 8; ++i) {
                    int r = top.first + dx[i], c = top.second + dy[i];
                    if (outside(r, c) or grid[r][c] == 1) {
                        continue;
                    }
                    if (isEnd(r, c)) {
                        return true;
                    }
                    q.push({r, c});
                    grid[r][c] = 1;
                }
            }
        }
        return false;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        if (grid.size() == 1) {
            return 1;
        }
        this->n = grid.size();
        if(bfs(grid)) {
            return step;
        }
        return -1;
    }
};
// @leet end
