// @leet start
#include <string>
using std::string;
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) { return false; }

        s += s;
        if (s.find(goal, 0) != string::npos) { return true; }

        return false;
    }
};
// @leet end
