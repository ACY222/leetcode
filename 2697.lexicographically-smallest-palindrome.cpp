// @leet start
#include <string>
using namespace std;
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] < s[n - 1 - i]) {
                s[n - 1 - i] = s[i];
            } else if (s[i] > s[n - 1 - i]) {
                s[i] = s[n - 1 - i];
            }
        }
        return s;
    }
};
// @leet end
