// @leet start
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                s[left] = s[right] = min(s[left], s[right]);
            }
            --right;
            ++left;
        }
        return s;
    }
};
// @leet end
