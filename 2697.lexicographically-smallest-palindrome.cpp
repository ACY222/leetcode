// @leet start
#include <string>
using namespace std;
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] < s[n - 1 - i]) {
                s[n - 1 - i] = s[i];
                ++count;
            } else if (s[i] > s[n - 1 - i]) {
                s[i] = s[n - 1 - i];
                ++count;
            }
        }
        return s;
    }
};
// @leet end
