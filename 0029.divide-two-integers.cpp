// @leet start
#include <climits>
class Solution {
public:
    // without * / %
    int divide(int dividend, int divisor) {
        // avoid overflow and handle with special cases
        if (dividend == INT_MIN and divisor == -1) { return INT_MAX; }
        if (dividend == INT_MIN and divisor == 1) { return INT_MIN; }

        bool is_negative = (dividend > 0) ^ (divisor > 0);

        if (dividend > 0) { dividend = -dividend; }
        if (divisor > 0) { divisor = -divisor; }

        int result = 0;

        for (int i = 31; i >= 0; --i) {
            if ((dividend >> i) <= divisor and dividend <= (divisor << i)) {
                dividend -= (divisor << i);
                result += (1 << i);
            }
        }

        return is_negative ? -result : result;
    }
};
// @leet end
