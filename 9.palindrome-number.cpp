// @leet start
#include <string>
using std::string;
// #include <stack>
//
// using std::stack;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }
        string x_str = std::to_string(x);
        for (auto i{0}; i < x_str.size() / 2; ++i) {
            if (x_str[i] != x_str[x_str.size() - i - 1]) { return false; }
        }
        return true;
        // // negative number won't be palindrome due to '-' symbol
        // if (x < 0) {
        //     return false;
        // }
        //
        // stack<int> st;
        //
        // while (x != 0) {
        //     st.push(x % 10);
        //     x /= 10;
        // }
    }
};
// @leet end
