// @leet start
#include <algorithm>
#include <iterator>
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
                auto it = lower_bound(matrix[row].begin(), matrix[row].begin() + col + 1, target);
                if (it != matrix[row].end() and *it == target) {
                    return true;
                }
                col = distance(matrix[row].begin(), it) - 1;
            }
        }
        return false;
    }
};
// @leet end
