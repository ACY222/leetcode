// @leet start
#include <utility>
#include <vector>
using namespace std;
class Solution {
private:
    const vector<pair<int, int>> start_dirs {{0, 1}, {1, 0}};
    const vector<pair<int, int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    struct Point {
        int x;
        int y;

        Point(int x, int y) : x(x), y(y) {}
        bool operator==(const Point& rhs) { return x == rhs.x and y == rhs.y; }
    };

    bool backtrace(const vector<vector<char>>& grid,
                   vector<vector<bool>>& visited, char val, const Point& start,
                   Point curr, int path_len) {
        for (auto& dir : dirs) {
            Point next(curr.x + dir.first, curr.y + dir.second);
            if (next.x < 0 or next.x >= grid.size() or next.y < 0
                or next.y >= grid[0].size()) {
                continue;
            }

            if (visited[next.x][next.y] == true
                or grid[next.x][next.y] != val) {
                continue;
            }

            if (next == start) {
                if (path_len >= 3) {
                    return true;
                } else {
                    continue;
                }
            }

            visited[next.x][next.y] = true;
            if (backtrace(grid, visited, val, start, next, path_len + 1)) {
                return true;
            }
            visited[next.x][next.y] = false;
        }

        return false;
    }

    bool checkCycle(const vector<vector<char>>& grid,
                    vector<vector<bool>>& visited, int x, int y) {
        char val = grid[x][y];
        Point start(x, y);
        for (auto& dir : start_dirs) {
            Point next(x + dir.first, y + dir.second);
            // in range && share the same value
            if (next.x < grid.size() and next.y < grid[0].size()
                and grid[next.x][next.y] == val) {

                visited[next.x][next.y] = true;
                if (backtrace(grid, visited, grid[x][y], start, next, 2)) {
                    return true;
                }
                visited[next.x][next.y] = false;
            }
        }

        return false;
    }

public:
    // the first step should be (0, 1) or (1, 0)
    // visited[x][y] = true if the four adjacent elements != visited[x][y]
    //
    // grid consists only lowercase English letters
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (checkCycle(grid, visited, x, y)) { return true; }
            }
        }

        return false;
    }
};
// @leet end
//
// a a a a
// a b b a
// a b b a
// a a a a
//
// c c c a
// c d c c
// c c e c
// f c c c
//
// a b b
// b z b
// b b a
