// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
  int total = 0;

  bool isValidPos(const vector<int>& nQueens, int row, int col, int n) {
    // check if there's a queen in the same column
    for (int i = 0; i < row; ++i) {
      if (nQueens[i] == col) {
        return false;
      }
    }
    // check if there's a queen in the same diagonal
    for (int i = 0; i < row; ++i) {
      if (nQueens[i] + i == col + row or nQueens[i] - i == col - row) {
        return false;
      }
    }
    return true;
  }

  void backtrack(vector<int>& nQueens, int start, int n) {
    if (start == n) {
      ++total;
    }

    for (int col = 0; col < n; ++col) {
      if (isValidPos(nQueens, start, col, n)) {
        nQueens.push_back(col);
        backtrack(nQueens, start + 1, n);
        nQueens.pop_back();
      }
    }
  }

public:
  int totalNQueens(int n) {
    vector<int> nQueens;
    backtrack(nQueens, 0, n);
    return total;
  }
};
// @leet end
