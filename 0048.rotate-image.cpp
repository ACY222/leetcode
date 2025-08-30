// @leet start
#include <vector>
using std::vector;
class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int n {(int)matrix.size()};
    for (int round = 0; round < n / 2; ++round) {
      for (int i = 0; i < n - 2 * round - 1; ++i) {
        int temp {matrix[round + 0][round + i]};
        matrix[round + 0][round + i] = matrix[-round + n - 1 - i][round];
        matrix[-round + n - 1 - i][round] = matrix[-round + n - 1][-round + n - 1 - i];
        matrix[-round + n - 1][-round + n - 1 - i] = matrix[round + i][-round + n - 1];
        matrix[round + i][-round + n - 1] = temp;
      }
    }
    return;
  }
};
// @leet end
