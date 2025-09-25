// @leet start
#include <cmath>
#include <vector>
using namespace std;
class Solution {
public:
    int  countPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ++count;
            }
            if (i < sqrt(n)) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return count;
    }
};
// @leet end
