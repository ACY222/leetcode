// @leet start
#include <cctype>
#include <climits>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;

        // trim the leading space
        auto idx_non_space = s.find_first_not_of(' ');
        if (idx_non_space == string::npos) { return 0; }
        int base_index = idx_non_space;

        if (s[base_index] == '-') {
            sign = -1;
            ++base_index;
        } else if (s[base_index] == '+') {
            ++base_index;
        } else if (!isdigit(s[base_index])) {
            return 0;
        }

        int res = 0;
        for (int i = base_index; i < s.size() and isdigit(s[i]); ++i) {
            int last = sign * (s[i] - '0');

            // judge if next result will be out of range
            if (res > INT_MAX / 10 or (res == INT_MAX / 10 and last > 7)) {
                return INT_MAX;
            }
            if (res < INT_MIN / 10 or (res == INT_MIN / 10 and last < -8)) {
                return INT_MIN;
            }

            res = res * 10 + last;
        }

        return res;
    }
};
// @leet end
