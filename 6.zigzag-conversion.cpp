// @leet start
#include <string>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) { return s; }

        string zigzag(s.size(), '\0');

        size_t index = 0;
        int may_next = 0;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < s.size(); j += 2 * numRows - 2) {
                zigzag[index++] = s[j];
                may_next = j + (2 * numRows - 2) - 2 * i;
                if (0 < i and i < numRows - 1 and may_next < s.size()) {
                    zigzag[index++] = s[may_next];
                }
            }
        }

        return zigzag;
    }
};
// @leet end
