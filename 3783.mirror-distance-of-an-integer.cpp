// @leet start
#include <algorithm>
#include <cstdlib>
using namespace std;
class Solution {
private:
    int reverse(int n) {
        int reverse_n = 0;
        while (n != 0) {
            reverse_n = 10 * reverse_n + n % 10;
            n /= 10;
        }

        return reverse_n;
    }

public:
    int mirrorDistance(int n) {
        int reverse_n = reverse(n);
        return abs(reverse_n - n);
    }
};
// @leet end
