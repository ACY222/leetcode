// @leet start
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
class Solution {
private:
    inline bool is_valid(int rows, int cols, int r, int c) {
        return r >= 0 and r < rows and c >= 0 and c < cols;
    }

    void cellsWithDist(int dist, vector<vector<int>>& cells, int rows, int cols,
                       int r, int c) {
        vector<pair<int, int>> groups {
            {r, c + dist}, {r + dist, c}, {r, c - dist}, {r - dist, c}
        };
        static const vector<pair<int, int>> dirs {
            {1, -1}, {-1, -1}, {-1, 1}, {1, 1}
        };

        for (int i = 0; i < dist; ++i) {
            for (int idx = 0; idx < 4; ++idx) {
                int row = groups[idx].first + dirs[idx].first * i;
                int col = groups[idx].second + dirs[idx].second * i;
                if (!is_valid(rows, cols, row, col)) { continue; }
                cells.push_back({row, col});
            }
        }
    }

public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                          int cCenter) {
        vector<vector<int>> cells;
        cells.reserve(rows * cols);
        cells.push_back({rCenter, cCenter});

        int max_dist = max(max(rCenter + cCenter, rows - 1 - rCenter + cCenter),
                           max(rCenter + cols - 1 - cCenter,
                               rows - 1 - rCenter + cols - 1 - cCenter));
        for (int dist = 1; dist <= max_dist; ++dist) {
            cellsWithDist(dist, cells, rows, cols, rCenter, cCenter);
        }
        return cells;
    }
};
// @leet end
