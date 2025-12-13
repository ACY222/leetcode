// @leet start
#include <string>

using namespace std;

class Solution {
public:
    // we need to check palindromic substrings with odd size and even size
    int countSubstrings(string s) {
        // every single character is a palindromic substring
        int count = s.size();
        // check substring with odd size
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 1; i - j >= 0 and i + j < s.size(); ++j) {
                if (s[i - j] == s[i + j]) {
                    ++count;
                }
                else {
                    break;
                }
            }
        }

        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] != s[i + 1]) {
                continue;
            }
            ++count;
            for (int j = 1; i - j >= 0 and i + 1 + j < s.size(); ++j) {
                if (s[i - j] == s[i + 1 + j]) {
                    ++count;
                }
                else {
                    break;
                }
            }
        }
        return count;
    }
};
// @leet end
