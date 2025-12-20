// @leet start
#include <cmath>

using namespace std;

class Solution {
private:
    bool is_square(int n) {
        int sq = sqrt(n);
        return n == sq * sq;
    }

public:
    // Use Lagrange's four-square theorem
    // Legendre's three-square theorem
    int numSquares(int n) {
        if (is_square(n)) {
            return 1;
        }

        int temp = n;
        while (temp % 4 == 0) {
            temp /= 4;
        }
        if (temp % 8 == 7) {
            return 4;
        }

        for (int i = 1; i * i < n; ++i) {
            if (is_square(n - i * i)) {
                return 2;
            }
        }

        return 3;
    }
};
// @leet end
