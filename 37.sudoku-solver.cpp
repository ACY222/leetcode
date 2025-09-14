// @leet start
#include <vector>
using namespace std;
class Solution {
private:

  static constexpr int N = 9;
  bool done = false;

  bool isValid(const vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < N; ++i) {
      if (board[i][col] == num or board[row][i] == num) {
        return false;
      }
    }
    int startRow = row / 3 * 3, startCol = col / 3 * 3;
    for (int i = startRow; i < startRow + 3; ++i) {
      for (int j = startCol; j < startCol + 3; ++j) {
        if (board[i][j] == num) {
          return false;
        }
      }
    }
    return true;
  }

  bool backtrack(vector<vector<char>>& board, int row, int col) {
    // go to another new row
    if (col == N) {
      col = 0;
      ++row;
      if (row == N) {
        return true;
      }
    }

    if (board[row][col] != '.') {
      if (backtrack(board, row, col + 1)) {
        return true;
      }
      return false;
    }

    for (char num = '1'; num <= '9'; ++num) {
      if (!isValid(board, row, col, num)) {
        continue;
      }
      board[row][col] = num;
      if (backtrack(board, row, col + 1)) {
        return true;
      }
      board[row][col] = '.';
    }
    return false;
  }
public:
  void solveSudoku(vector<vector<char>>& board) {
    backtrack(board, 0, 0);
  }
};
// @leet end
