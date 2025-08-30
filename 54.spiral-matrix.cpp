// @leet start
#include <algorithm>
#include <vector>
using std::vector;
using std::min;
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rowSize {(int)matrix.size()}, columnSize {(int)matrix[0].size()};
    int size {min(rowSize, columnSize)};
    vector<int> res {};
    for (int base = 0; base < (size + 1) / 2; ++base) {
      int i = 1, j = 0;
      while (j < columnSize - 2 * base) {
        res.push_back(matrix[base][base + j]);
        ++j;
      }
      while (i < rowSize - 2 * base) {
        res.push_back(matrix[base + i][-base + columnSize - 1]);
        ++i;
      }
      if (2 * base != rowSize - 1) {
        // size - 1 to reach the last element, -2*base to ignore the round
        // calculated before, -1 to ignore the element calculated just now
        j = columnSize - 1 - 2 * base - 1;
        while (j >= 0) {
          res.push_back(matrix[-base + rowSize - 1][base + j]);
          --j;
        }
      }
      if (2 * base != columnSize - 1) {
        i = rowSize - 1 - 2 * base - 1;
        while (i > 0) {
          res.push_back(matrix[base + i][base]);
          --i;
        }
      }
    }
    return res;
  }
};
// @leet end
