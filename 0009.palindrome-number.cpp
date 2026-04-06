// @leet start
#include <climits>
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }
        auto x_rev{0};
        auto x_copy{x};

        while (x_copy != 0) {
            auto last{x_copy % 10};
            if (x_rev > INT_MAX / 10 or (x_rev == INT_MAX / 10 and last > 7)) {
                return false;
            }
            x_rev = x_rev * 10 + last;
            x_copy /= 10;
        }

        return x == x_rev ? true : false;
    }
};
// @leet end
