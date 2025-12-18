// @leet start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        static const auto io_sync_off = []() {
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            return nullptr;
        }();
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;
        while (row < m and col >= 0) {
            int curr = matrix[row][col];

            if (curr == target) {
                return true;
            }
            else if (curr < target) {
                ++row;
            }
            else {
                --col;
            }
        }
        return false;
    }
};
// @leet end
