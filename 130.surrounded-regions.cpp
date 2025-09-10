// @leet start
#include <vector>
using std::vector;
class Solution {
private:
  int m, n;
  // change all the 'O' which is not connected to the border to 'X'
  void dfs(vector<vector<char>>& board, int i, int j) {
    if (i < 0 or i >= m or j < 0 or j >= n) {
      return;
    }
    if (board[i][j] != 'O') {
      return;
    }
    board[i][j] = '#';
    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
  }

public:
  void solve(vector<vector<char>>& board) {
    m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
      dfs(board, i, 0);
      dfs(board, i, n - 1);
    }
    for (int j = 1; j < n - 1; ++j) {
      dfs(board, 0, j);
      dfs(board, m - 1, j);
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '#') {
          board[i][j] = 'O';
        }
      }
    }
  }
};
// @leet end
