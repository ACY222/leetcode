// @leet start
#include <string>
using namespace std;
class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for (char ch : s) {
            if (ch < '0' or ch > '9') { continue; }
            int digit = ch - '0';

            // first, digit, second
            if (first > digit and digit > second) {
                second = digit;
            }
            // digit, first, second
            else if (digit > first) {
                second = first;
                first = digit;
            }
        }

        return second;
    }
};
// @leet end
