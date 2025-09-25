// @leet start
#include <vector>
using namespace std;

class Solution {
    const int base = 1337;
    int myPow(int a, int k) {
        if (k == 0) {
            return 1;
        }

        a %= base;

        if (k % 2 == 1) {
            return (a * myPow(a, k - 1)) % base;
        }
        else {
            int sub = myPow(a, k / 2);
            return (sub * sub) % base;
        }

    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) {
            return 1;
        }
        // if b is not empty
        int last = b.back();
        b.pop_back();
        int part1 = myPow(a, last);
        int part2 = myPow(superPow(a, b), 10);
        return (part1 * part2) % base;
    }
};
// @leet end
