// @leet start
#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<string>> output;    // used to store the results

  bool isValidPos(vector<string>& board, int row, int col, int n) {
    // check if there's a queen in the same column
    for (int i = 0; i < row; ++i) {
      if (board[i][col] == 'Q') {
        return false;
      }
    }
    // check if there's a queen in the same upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; --i, --j) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }
    // check if there's a queen in the same upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 and j < n; --i, ++j) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }

  void backtrack(vector<string>& board, int row, int n) {
    if (row == n) {
      output.push_back(board);
    }

    for (int col = 0; col < n; ++col) {
      if (isValidPos(board, row, col, n)) {
        board[row][col] = 'Q';
        backtrack(board, row + 1, n);
        board[row][col] = '.';
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0, n);
    return output;
  }
};
// @leet end
