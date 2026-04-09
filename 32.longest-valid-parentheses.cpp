// @leet start
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> is_valid(s.size(), false);
        stack<pair<char, int>> st;

        for (int i = 0; i < s.size(); ++i) {
            char val = s[i];

            // if current ')' matches '(' in the stack
            if (val == ')') {
                if (!st.empty() and st.top().first == '(') {
                    is_valid[i] = true;
                    is_valid[st.top().second] = true;
                    st.pop();
                }
                // else {
                //     st.emplace(val, i);
                // }
            } else {
                st.emplace(val, i);
            }
        }

        int longest_valid = 0;
        for (int i = 0; i < s.size(); ++i) {
            // skip if invalid
            if (!is_valid[i]) { continue; }

            int curr_valid = 0;
            while (is_valid[i]) {
                ++curr_valid;
                ++i;
            }
            longest_valid = max(curr_valid, longest_valid);
        }
        return longest_valid;
    }
};
// @leet end
