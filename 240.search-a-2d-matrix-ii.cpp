// @leet start
#include <vector>

using namespace std;

class Solution {
private:
    bool searchMatrixPartially(vector<vector<int>>& matrix, int target, int row_start, int row_end,
                               int col_start, int col_end) {
        if (row_start < 0 or row_end >= matrix.size() or col_start < 0 or col_end >= matrix[0].size()) {
            return false;
        }
        if (row_start > row_end or col_start > col_end) {
            return false;
        }
        int row_mid = (row_start + row_end) / 2, col_mid = (col_start + col_end) / 2;
        int current_num = matrix[row_mid][col_mid];
        if (current_num == target) {
            return true;
        }
        else if (current_num < target) {
            return
                searchMatrixPartially(matrix, target, row_start, row_mid, col_mid + 1, col_end)
                or
                searchMatrixPartially(matrix, target, row_mid + 1, row_end, col_start, col_end);
        }
        else {
            return
                searchMatrixPartially(matrix, target, row_start, row_mid - 1, col_start, col_end)
                or
                searchMatrixPartially(matrix, target, row_mid, row_end, col_start, col_mid - 1);
        }
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrixPartially(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }
};
// @leet end
