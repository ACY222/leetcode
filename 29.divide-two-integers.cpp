// @leet start
#include <climits>
class Solution {
public:
    // without * / %
    int divide(int dividend, int divisor) {
        // avoid overflow and handle with special cases
        if (dividend == INT_MIN and divisor == -1) { return INT_MAX; }
        if (dividend == 0) { return 0; }
        if (divisor == 1) { return dividend; }
        if (divisor == -1) { return -dividend; }

        bool is_negative = (dividend > 0) ^ (divisor > 0);

        if (dividend > 0) { dividend = -dividend; }
        if (divisor > 0) { divisor = -divisor; }

        int result = 0;

        while (dividend <= divisor) {
            int temp_divisor = divisor;
            int count = 1;

            while (divisor >= (INT_MIN >> 1)
                   and dividend <= (temp_divisor << 1)) {
                temp_divisor <<= 1;
                count <<= 1;
            }

            dividend -= temp_divisor;
            result += count;
        }

        return is_negative ? -result : result;
    }
};
// @leet end
