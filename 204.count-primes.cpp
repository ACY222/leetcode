// @leet start
#include <vector>
using namespace std;
class Solution {
    bool is_prime(int x) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int countPrimes(int n) {
        vector<bool> bits(n, true);
        for (int i = 2; i * i < n; ++i) {
            if (!is_prime(i)) {
                continue;
            }
            for (int j = i * i; j < n; j += i) {
                bits[j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (bits[i]) {
                ++count;
            }
        }
        return count;
    }
};
// @leet end
