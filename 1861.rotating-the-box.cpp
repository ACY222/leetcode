// @leet start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> box(n, vector<char>(m));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                box[j][m - i - 1] = boxGrid[i][j];
            }
        }

        for (int j = 0; j < m; ++j) {
            int lowest = n;
            for (int i = n - 1; i > 0; --i) {
                if (box[i][j] != '.') { continue; }

                if (lowest >= i) { lowest = i - 1; }

                while (lowest >= 0) {
                    if (box[lowest][j] == '.') {
                        --lowest;
                    } else if (box[lowest][j] == '*') {
                        i = lowest;
                        lowest -= 2;
                        break;
                    } else {
                        swap(box[lowest][j], box[i][j]);
                        --lowest;
                        break;
                    }
                }

                if (lowest < 0) { continue; }
            }
        }

        return box;
    }
};
// @leet end
