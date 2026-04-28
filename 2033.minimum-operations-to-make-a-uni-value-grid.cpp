// @leet start
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> sorted(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sorted[i * n + j] = grid[i][j];
                if ((grid[i][j] - grid[0][0]) % x != 0) { return -1; }
            }
        }

        sort(sorted.begin(), sorted.end());
        int mid_idx = m * n / 2, num_operations = 0;
        for (int i = 0; i < m * n; ++i) {
            num_operations += abs(sorted[i] - sorted[mid_idx]);
        }

        return num_operations / x;
    }
};
// @leet end
