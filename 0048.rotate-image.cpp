// @leet start
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    // rotate by 90 degrees clockwise = transpose + reverse each row
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }


        for (auto& rows : matrix) {
            reverse(rows.begin(), rows.end());
        }
    }
};
// @leet end
