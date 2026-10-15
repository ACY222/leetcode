// @leet start
#include <vector>
using std::vector;
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        constexpr int rows = 8, cols = 8;
        int r, c;
        int num = 0;
        for (r = 0; r < rows; ++r) {
            for (c = 0; c < cols; ++c) {
                if (board[r][c] == 'R') { break; }
            }

            if (c != cols) {
                // now board[r][c] == rook
                for (int left = c - 1; left >= 0; --left) {
                    if (board[r][left] == '.') {
                        continue;
                    } else {
                        if (board[r][left] == 'p') { ++num; }
                        break;
                    }
                }

                for (int right = c + 1; right < cols; ++right) {
                    if (board[r][right] == '.') {
                        continue;
                    } else {
                        if (board[r][right] == 'p') { ++num; }
                        break;
                    }
                }

                for (int up = r - 1; up >= 0; --up) {
                    if (board[up][c] == '.') {
                        continue;
                    } else {
                        if (board[up][c] == 'p') { ++num; }
                        break;
                    }
                }

                for (int bottom = r + 1; bottom < rows; ++bottom) {
                    if (board[bottom][c] == '.') {
                        continue;
                    } else {
                        if (board[bottom][c] == 'p') { ++num; }
                        break;
                    }
                }

                break;
            }
        }

        return num;
    }
};
// @leet end
