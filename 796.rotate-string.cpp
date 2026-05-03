// @leet start
#include <string>
using std::string;
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) { return false; }

        int n = s.size();
        for (int offset = 0; offset < n; ++offset) {
            int i = 0;
            for (; i < n; ++i) {
                if (s[(offset + i) % n] != goal[i]) { break; }
            }

            if (i == n) { return true; }
        }

        return false;
    }
};
// @leet end
