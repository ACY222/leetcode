// @leet start
#include <cctype>
#include <stack>
#include <string>
using std::string;
using std::stack;
class Solution {
public:
  int calculate(string s) {
    // signs shows the sign for the sum in the brackets
    // isPositive shows the pos/neg of the last sign
    stack<int> signs({1});
    int total = 0, isPositive = 1, num = 0;
    for (char c : s) {
      if (isdigit(c)) {
        num = num * 10 + (c - '0');
      }
      else {
        total += num * isPositive * signs.top();
        num = 0;
        switch (c) {
          case '-': isPositive = -1; break;
          case '+': isPositive = 1;  break;
          case ')': signs.pop(); break;
          case '(':
            signs.push(signs.top() * isPositive);
            isPositive = 1;
        }
      }
    }
    total += num * isPositive * signs.top();
    return total;
  }
};
// @leet end
