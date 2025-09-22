// @leet start
#include <utility>
class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        int x = 0, y = 1;

        for (int i = 2; i <= n; ++i) {
            x = x + y;
            std::swap(x, y);
        }
        return y;
    }
};
// @leet end
