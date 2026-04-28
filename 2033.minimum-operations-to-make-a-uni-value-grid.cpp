// @leet start
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int mod = grid[0][0] % x;

        vector<int> nums;
        nums.reserve(m * n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] % x != mod) { return -1; }
                nums.push_back(grid[i][j]);
            }
        }

        int mid_idx = m * n / 2, num_operations = 0;
        nth_element(nums.begin(), nums.begin() + mid_idx, nums.end());
        int median = nums[mid_idx];
        for (int i = 0; i < m * n; ++i) {
            num_operations += abs(nums[i] - median);
        }

        return num_operations / x;
    }
};
// @leet end
