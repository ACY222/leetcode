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
    stack<int> signsForBracket({1});
    int total = 0, currSign = 1, num = 0;
    for (char c : s) {
      if (isdigit(c)) {
        num = num * 10 + (c - '0');
      }
      else {
        total += num * currSign * signsForBracket.top();
        num = 0;
        switch (c) {
          case '-': currSign = -1; break;
          case '+': currSign = 1;  break;
          case ')': signsForBracket.pop(); break;
          case '(':
            signsForBracket.push(signsForBracket.top() * currSign);
            currSign = 1;
        }
      }
    }
    total += num * currSign * signsForBracket.top();
    return total;
  }
};
// @leet end
