// @leet start
#include <string>
using namespace std;
class Solution {
public:
    // `?`: 1 char
    // `*`: 0-infinity chars
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int match_idx = -1, star_idx = -1;

        while (i < s.size()) {
            // if p[j] and s[i] matches
            if (j < p.size() and (p[j] == '?' or p[j] == s[i])) {
                i++;
                j++;
            } else if (j < p.size() and p[j] == '*') {
                // suppose * matches 0 char
                star_idx = j;
                match_idx = i;
                j++;
            } else if (star_idx != -1) {
                j = star_idx + 1;
                match_idx++;
                i = match_idx;
            } else {
                return false;
            }
        }

        while (j < p.size() and p[j] == '*') {
            ++j;
        }

        return j == p.size();
    }
};
// @leet end
