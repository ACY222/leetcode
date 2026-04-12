// @leet start
#include <array>
#include <vector>

using namespace std;
class Solution {
public:
    // only filled cells need to be validated
    bool isValidSudoku(vector<vector<char>>& board) {
        array<array<int, 9>, 9> rows {false};
        array<array<int, 9>, 9> cols {false};
        array<array<int, 9>, 9> boxes {false};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') { continue; }

                int num = board[r][c] - '1';
                int box_idx = (r / 3) * 3 + c / 3;

                if (rows[r][num] or cols[c][num] or boxes[box_idx][num]) {
                    return false;
                }

                rows[r][num] = true;
                cols[c][num] = true;
                boxes[box_idx][num] = true;
            }
        }

        return true;
    }
};
// @leet end
