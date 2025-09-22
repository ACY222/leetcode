// @leet start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:

    void fall_from_top(vector<vector<int>>& matrix, int n) {
        // i indicates the row, k indicates the column
        for (int i = 1; i < n; ++i) {
            matrix[i][0] = min(matrix[i - 1][0], matrix[i - 1][1]) +
                matrix[i][0];
            for (int k = 1; k < n - 1; ++k) {
                matrix[i][k] = min(min(matrix[i - 1][k - 1], matrix[i - 1][k]),
                    matrix[i - 1][k + 1]) + matrix[i][k];
            }
            matrix[i][n - 1] = min(matrix[i - 1][n - 2], matrix[i - 1][n - 1]) +
                matrix[i][n - 1];
        }
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) {
            return matrix[0][0];
        }
        fall_from_top(matrix, matrix.size());
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};
// @leet end
