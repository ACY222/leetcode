// @leet start
#include <vector>
using namespace std;
class Solution {
private:

  static constexpr int N = 9;

  bool isValid(const vector<vector<char>>& board,
               const int row, const int col, const char num) {
    for (int i = 0; i < N; ++i) {
      if (board[i][col] == num or board[row][i] == num) {
        return false;
      }
    }
    int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; ++i) {
      for (int j = startCol; j < startCol + 3; ++j) {
        if (board[i][j] == num) {
          return false;
        }
      }
    }
    return true;
  }

  bool backtrack(vector<vector<char>>& board, int startRow) {
    for (int row = startRow; row < N; ++row) {
      for (int col = 0; col < N; ++col) {
        if (board[row][col] == '.') {
          for (char num = '1'; num <= '9'; ++num) {
            if (isValid(board, row, col, num)) {
              board[row][col] = num;
              if (backtrack(board, row)) {
                return true;
              }
              board[row][col] = '.';
            }
          }
          return false; // have tries all values, but failed
        }
      }
    }
    return true;
  }
public:
  void solveSudoku(vector<vector<char>>& board) {
    backtrack(board, 0);
  }
};
// @leet end
