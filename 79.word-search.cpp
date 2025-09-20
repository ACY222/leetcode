// @leet start
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    int m, n;
    static constexpr char mark = '#';
    const vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    inline bool outside(int row, int col) {
        return (row < 0 or row >= m or col < 0 or col >= n);
    }
    // now word[index - 1] == board[r][c]
    // we are looking for pos where board[row][col] == word[index]
    bool backtrack(vector<vector<char>>& board, int r, int c,
                   string& word, int index) {
        if (index == word.size()) {
            return true;
        }

        for (const auto& dir : dirs) {
            int row = r + dir[0], col = c + dir[1];
            if (outside(row, col)) {
                continue;
            }

            if (board[row][col] == word[index]) {
                // mark the board to avoid searching back
                board[row][col] = mark;
                if (backtrack(board, row, col, word, index + 1)) {
                    return true;
                }
                board[row][col] = word[index];
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    board[i][j] = mark;
                    if (backtrack(board, i, j, word, 1)) {
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};
// @leet end
