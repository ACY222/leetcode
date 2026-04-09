// @leet start
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> indices;

        for (int i = 0; i < s.size(); ++i) {
            // if current ')' matches '('
            if (s[i] == ')' and !indices.empty() and s[indices.top()] == '(') {
                indices.pop();
            } else {
                indices.push(i);
            }
        }

        int longest_valid = 0;
        auto curr {static_cast<int>(s.size())};

        while (!indices.empty()) {
            auto next {indices.top()};
            indices.pop();
            longest_valid = max(longest_valid, curr - next - 1);
            curr = next;
        }

        longest_valid = max(longest_valid, curr);
        return longest_valid;
    }
};
// @leet end
