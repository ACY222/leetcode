// @leet start
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        auto num_longest_valid {0};
        auto num_left {0}, num_right {0};

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++num_left;
            } else {
                ++num_right;
                if (num_right == num_left) {
                    num_longest_valid = max(num_longest_valid, 2 * num_right);
                } else if (num_right > num_left) {
                    num_left = 0, num_right = 0;
                }
            }
        }

        num_left = 0, num_right = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++num_right;
            } else {
                ++num_left;
                if (num_left == num_right) {
                    num_longest_valid = max(num_longest_valid, 2 * num_left);
                } else if (num_left > num_right) {
                    num_left = 0, num_right = 0;
                }
            }
        }

        return num_longest_valid;
    }
};
// @leet end
