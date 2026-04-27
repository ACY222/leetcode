// @leet start
#include <array>
#include <utility>
#include <vector>
using namespace std;
class Solution {
private:
    const array<vector<pair<int, int>>, 7> street_to_dirs = {{
        {},
        {{0, -1}, {0, 1}},
        {{-1, 0}, {1, 0}},
        {{0, -1}, {1, 0}},
        {{0, 1}, {1, 0}},
        {{0, -1}, {-1, 0}},
        {{0, 1}, {-1, 0}},
    }};

    bool canReturn(const vector<vector<int>>& grid, int cx, int cy, int nx,
                   int ny) {
        for (const auto dir : street_to_dirs[grid[nx][ny]]) {
            auto [dx, dy] = dir;
            int px = nx + dx, py = ny + dy;
            if (px == cx and py == cy) { return true; }
        }

        return false;
    }

    bool canReach(vector<vector<bool>>& visited,
                  const vector<vector<int>>& grid, int cx, int cy) {
        visited[cx][cy] = true;
        if (cx == grid.size() - 1 and cy == grid[0].size() - 1) { return true; }

        for (const auto dir : street_to_dirs[grid[cx][cy]]) {
            auto [dx, dy] = dir;

            int nx = cx + dx, ny = cy + dy;

            if (nx < 0 or nx >= grid.size() or ny < 0 or ny >= grid[0].size()) {
                continue;
            }
            if (visited[nx][ny]) { continue; }

            if (!canReturn(grid, cx, cy, nx, ny)) { continue; }

            if (canReach(visited, grid, nx, ny)) { return true; }
        }

        return false;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));
        return canReach(visited, grid, 0, 0);
    }
};
// @leet end
