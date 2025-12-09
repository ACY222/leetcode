#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size(), max_size = 0;
        vector<int> dp(n, 0);
        for (int row = 0; row < m; ++row) {
            int prev = 0, curr = 0;
            for (int col = 0; col < n; ++col) {
                curr = dp[col];
                if (row == 0 or col == 0 or matrix[row][col] == '0') {
                    dp[col] = matrix[row][col] - '0';
                }
                else {      // matrix[row][col] == '1'
                    dp[col] = min(prev, min(dp[col], dp[col - 1])) + 1;
                }
                max_size = max(dp[col], max_size);
                prev = curr;
            }
        }
        return max_size * max_size;
    }
};