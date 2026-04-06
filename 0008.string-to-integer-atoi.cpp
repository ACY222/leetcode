// @leet start
#include <cctype>
#include <string>

using std::string;
class Solution {
public:
    int myAtoi(string s) {
        // trim the leading whitespace
        auto is_neg{1};
        auto base_index{s.find_first_not_of(' ')};
        if (base_index == string::npos) { return 0; }
        if (s[base_index] == '-') {
            is_neg = -1;
            ++base_index;
        } else if (s[base_index] == '+') {
            ++base_index;
        } else if (!isdigit(s[base_index])) {
            return 0;
        }

        auto res{0};
        for (auto i{base_index}; i < s.size() and isdigit(s[i]); ++i) {
            auto last{is_neg * (s[i] - '0')};
            if (is_neg
                and (res < INT_MIN / 10
                     or (res == INT_MIN / 10 and last < -8))) {
                return INT_MIN;
            } else if (res > INT_MAX / 10
                       or (res == INT_MAX / 10 and last > 7)) {
                return INT_MAX;
            }

            res = res * 10 + last;
        }

        return res;
    }
};
// @leet end
