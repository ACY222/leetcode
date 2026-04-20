// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                          int cCenter) {
        int max_dist =
            max(rCenter, rows - 1 - rCenter) + max(cCenter, cols - 1 - cCenter);

        vector<vector<vector<int>>> buckets(max_dist + 1);

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int dist = abs(r - rCenter) + abs(c - cCenter);
                buckets[dist].push_back({r, c});
            }
        }

        vector<vector<int>> cells;
        cells.reserve(rows * cols);

        for (int dist = 0; dist <= max_dist; ++dist) {
            for (auto& cell : buckets[dist]) {
                cells.push_back({cell});
            }
        }
        return cells;
    }
};
// @leet end
